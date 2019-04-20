/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:06:08 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 22:03:15 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"


int		get_window_pixel_size(t_environment *e)
{
	static int		size;
	int				w;
	int				h;

	if (e->win_ev.size_changed || !size)
	{
		if (e == NULL)
			return (0);
		SDL_GetWindowSize(e->window, &w, &h);
		size = w * h;
	}
	return (size);
}

static int		get_window_width(t_environment *e)
{
	static int	w;
	int			h;

	if (e->win_ev.size_changed || !w)
	{
		if (e == NULL)
			return (0);
		SDL_GetWindowSize(e->window, &w, &h);
	}
	return (w);
}

static int		get_window_height(t_environment *e)
{
	static int		h;
	int				w;

	if (e->win_ev.size_changed || !h)
	{
		if (e == NULL)
			return (0);
		SDL_GetWindowSize(e->window, &w, &h);
	}
	return (h);
}

int				render_roof()
{
	return (1);
}

int				get_ceiling_projected_size(t_sector *start, t_sector *actual,
						t_hit *hit, t_environment *e)
{
	double		ceiling_disp;

	ceiling_disp = start->ceil - actual->ceil;
	if (ceiling_disp < 0)
		return (0);
	ceiling_disp = (ceiling_disp / hit->distance) * e->player.dist_plane;
	return ((int)ceiling_disp);
}

int				get_floor_projected_size(t_sector *start, t_sector *actual,
						t_hit *hit, t_environment *e)
{
	double		floor_disp;

	floor_disp = actual->ceil - start->ceil;
	if (floor_disp < 0)
		return (0);
	floor_disp = (floor_disp / hit->distance) * e->player.dist_plane;
	return ((int)floor_disp);
}

int				get_projected_wall_size(t_sector *actual, t_hit *hit, t_environment *e)
{
	double		wall_height;

	wall_height = actual->ceil - actual->floor;
	wall_height = (wall_height / hit->distance) * e->player.dist_plane;
	return ((int)wall_height);
}
/*
static void				set_pixel(t_texture *tex, Uint32 c, t_vector2i p)
{
	(tex->pixels)[p.y * tex->s.x + p.x] = c;
}

static void				draw_column(t_line ln, t_vector2i s,
									SDL_Surface *surface, t_texture *tx)
{
	t_vector2i	scr_cd;
	t_vector2i	sur_cd;
	t_vector2f	wall_unit;
	t_vector2i	clamped_ln;

	sur_cd.x = (int)((ln.dist - (int)ln.dist) * (float)surface->w);
	scr_cd = (t_vector2i){ln.x, (int)0};
	clamped_ln.x = ((s.y - ln.h) / 2.0f < 0) ? 0 : (s.y - ln.h) / 2.0f;
	clamped_ln.y = ((ln.h + s.y) / 2.0f >= s.y) ? s.y - 1 : (ln.h + s.y) / 2.0f;
	while (scr_cd.y < s.y)
	{
		if (scr_cd.y < clamped_ln.x)
			set_pixel(tx, SDL_MapRGBA(tx->format, 100, 100, 255, 255), scr_cd);
		else if (scr_cd.y >= clamped_ln.x && scr_cd.y < clamped_ln.y)
		{
			wall_unit.y = ((scr_cd.y - ln.dr.x) / (float)(ln.dr.y - ln.dr.x));
			sur_cd.y = (int)(wall_unit.y / (1.0F / (float)surface->h));
			set_pixel(tx, ((Uint32*)surface->pixels)[sur_cd.y * surface->w
					+ sur_cd.x], scr_cd);
		}
		else
			set_pixel(tx, SDL_MapRGBA(tx->format, 100, 100, 100, 255), scr_cd);
		scr_cd.y++;
	}
}
*/
void			draw_color_line(t_vector2i s, int m, Uint32 color, t_renderer_env *re)
{
	while (s.y < m)
	{
		re->p[s.y * re->size.y + s.x] = color;
		s.y ++;
	}
}

int				render_wall(t_renderer_env *re, t_environment *e)
{
	t_vector3i fwc;
	t_sector	*n_sec;

	cast_ray(re->ray, re->hit, e->level);
	while (re->hit->result)
	{
		if (re->hit->type == 2) // wall
		{
			fwc.y = (re->size.y
				- get_projected_wall_size(e->player.cur_sector, re->hit, e)) / 2;
			draw_color_line((t_vector2i){re->c.x, 0}, fwc.y, 0xff0932, re);
			draw_color_line((t_vector2i){re->c.x, 0}, fwc.y, 0x32ff09, re);
			draw_color_line((t_vector2i){re->c.x, 0}, fwc.y, 0x0932ff, re);
			//render wall
			re->hit->result = 0;
		}
		else if (re->hit->type == 1) // gate
		{
			n_sec = e->level->sector[((t_gate*)((t_wall*)
					(re->hit->target))->gate)->sector_2];
			fwc.x = get_floor_projected_size(e->player.cur_sector, n_sec, re->hit, e);
			fwc.y = (re->size.y
					- get_projected_wall_size(e->player.cur_sector, re->hit, e)) / 2;
			fwc.z = get_ceiling_projected_size(e->player.cur_sector, n_sec, re->hit, e);
			int		test = (re->size.y - (fwc.x + fwc.y + fwc.z)) / 2; 
			draw_color_line((t_vector2i){re->c.x, 0}, test, 0xff0932, re);
			draw_color_line((t_vector2i){re->c.x, test}, fwc.z, 0xffd609, re);
			draw_color_line((t_vector2i){re->c.x, fwc.z}, fwc.y, 0x09ffd6, re);
			draw_color_line((t_vector2i){re->c.x, 0}, fwc.y, 0xff5b09, re);
			draw_color_line((t_vector2i){re->c.x, 0}, fwc.y, 0x0932ff, re);
			/*
				0 a fwc.z -> plafond
				fwc.z a fwc.y = denivelle haut,
				fwc.y a fwc.x nouveau plane (mur vide)
				fwc.x a H sol
			*/
			// rendu sol ici 
			// render floor and ceiling for the next sector
			// plane_nouuvelles valeurs
			//set_ray_direction(&(re->ray), n_sec->id, re->hit->pos, re->ray.dir);
			//re->ray.exluded_wall = ((t_gate*)((t_wall*)(re->hit->target))->gate)->wall_2;
			//cast_ray(re->ray, re->hit, e->level);
		}
	}
	return (1);
}

int				render_walls(t_environment *e, t_renderer_env *re, t_hit *h)
{
	t_vector2i		c;
	double			cx;

	c.x = -1;
	while (c.x++ < get_window_width(e))
	{
	printf ("test\n");	

		cx = 2 * c.x / get_window_width(e) - 1;
		set_ray_direction(&(re->ray), e->player.sec_id, e->player.pos,
			(t_vector2d){(float)(e->player.rot.x + e->player.plane.x
				* cx), (float)(e->player.rot.y + e->player.plane.y * cx)});
		set_ray_options(&(re->ray), RAYCAST_WALLS, 0);
		re->c = (t_vector2i) {c.x, 0};
		re->hit = &(h[c.x]);
		render_wall(re, e);
	}
	return (1);
}

static int			fill_renv(t_renderer_env *renv, t_environment *e, SDL_Texture *tex)
{
	int		pitch;
	void	*tmp;

	renv->c = (t_vector2i) {(int)0, (int)0};
	renv->size = (t_vector2i)
			{
				(int)get_window_width(e),
				(int)get_window_height(e)
			};
	if (SDL_LockTexture(tex, NULL, &(tmp), &pitch)== -1)
		return (0);
	renv->p = tmp;
	return (1);
}

int				render_frame(t_environment *e)
{
	static SDL_Texture		*tex;
	static t_hit			*hit_buffer;
	t_renderer_env			renv;

	if (!tex || e->win_ev.size_changed || !hit_buffer)
	{
		if (!(tex = get_fsdl_texture(e, &tex))
				|| !(hit_buffer = get_hit_buffer(e, &hit_buffer)))
			return (0);
	}
	if (SDL_RenderClear(e->renderer) == -1
		|| !(fill_renv(&renv, e, tex)))
	{
		ft_putstr(SDL_GetError());
		return (0);
	}
	render_walls(e, &renv, hit_buffer);
	clear_hit_buffer(get_window_width(e), &hit_buffer);
	SDL_UnlockTexture(tex);
	if (SDL_RenderCopy(e->renderer, tex, NULL, NULL) == -1)
	{
		perror(SDL_GetError());
		return (0);
	}
	SDL_RenderPresent(e->renderer);
	return (1);
}
