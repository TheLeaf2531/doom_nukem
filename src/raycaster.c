/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:29:24 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 17:25:15 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static void				set_hit_info(t_hit *hit, t_level *level, t_ray ray,
							int object_id)
{
	hit->distance = sqrtl(powl(ray.pos.x - hit->pos.x, 2.0)
		+ powl(ray.pos.y - hit->pos.y, 2.0));
	hit->sector = level->sector[ray.c_sector];
	hit->result = 1;
	if ((ray.flags) & RAYCAST_WALLS)
	{
		hit->type = level->sector[ray.c_sector]->wall[object_id]->is_gate
						? 1 : 2;
		hit->target = level->sector[ray.c_sector]->wall[object_id];
	}
	else
		hit->type = -1;
	
}

static void				s_change(t_wall *w, t_ray *ray)
{
	ray->c_sector = ((t_gate*)(w->gate))->sector_2;
	ray->exluded_wall = ((t_gate*)w->gate)->wall_2->id;
}

static void 			raycast_wall(t_ray ray, t_hit *hit, t_level *level)
{
	int		i;

	i = 0;
	ray.c_flag = RAYCAST_WALLS;
	while (!hit->result && i < level->sector[ray.c_sector]->walls)
	{
		if (ray.exluded_wall != i)
		{
			if (check_wall_intersection(ray, hit,
				level->sector[ray.c_sector]->wall[i]))
			{
				if (level->sector[ray.c_sector]->wall[i]->is_gate
					&& ((ray.flags) & RAYCAST_GATES))
				{
					s_change(level->sector[ray.c_sector]->wall[i], &ray);
					raycast_wall(ray, hit, level);
				}
				else
					set_hit_info(hit, level, ray, i);
			}
			else
				hit->result = 0;
		}
		i++;
	}
}




void					cast_ray(t_ray ray, t_hit *hit, t_level *level)
{
	ray.matrix = (t_vector3d) {(double)ray.dir.y, (double)-ray.dir.x,
						-(ray.dir.x * ray.pos.y - ray.dir.y * ray.pos.x)};
	hit->result = 0;
	if ((ray.flags) & RAYCAST_WALLS)
	{
		raycast_wall(ray, hit, level);
	}
	else
		printf("Not implemented, fuck you\n");
	/*if ((ray.flags) & (1<<(RAYCAST_SPRITES)))
	{

	}*/
}

/*

t_hit				test_hit(t_wall *w, t_ray *ray, t_hit hit)
{
	if (w->w_type == 0 && w->gate && !ray->gate_stop)
	{
		ray->current_sector = w->gate->s_in == ray->current_sector
				? w->gate->s_out : w->gate->s_in;
		ray->excluded_wall = w->gate->s_in == ray->current_sector
				? w->gate->w_in->w_id : w->gate->w_out->w_id;
		hit = cast_ray(*ray);
	}
	else
	{
		hit.dist = sqrtf(powl(ray->origin.x - hit.pos.x, 2.0F)
				+ powl(ray->origin.y - hit.pos.y, 2.0F));
		hit.result = !w->gate ? 1 : 2;
		hit.type = w->w_type;
		hit.wall = w;
	}
	return (hit);
}
*/
