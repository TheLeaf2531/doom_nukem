/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:01:23 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/19 20:54:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

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


static int				check_wall_coherence(t_ray ray, t_vector2d s, t_vector2d e, t_hit *hit)
{
	int				is_legit;
	t_vector2f		ran_x;
	t_vector2f		ran_y;

	is_legit = 1;
	ran_x.x = s.x < e.x ? s.x : e.x;
	ran_x.y = s.x < e.x ? e.x : s.x;
	ran_y.x = s.y < e.y ? s.y : e.y;
	ran_y.y = s.y < e.y ? e.y : s.y;
	if ((ray.dir.x < 0.0 && hit->pos.x > ray.pos.x)
			|| (ray.dir.y < 0.0 && hit->pos.y > ray.pos.y)
			|| (ray.dir.x > 0.0 && hit->pos.x < ray.pos.x)
			|| (ray.dir.y > 0.0 && hit->pos.y < ray.pos.y))
		is_legit = 0;
	else if (hit->pos.x < ran_x.x - 0.0001 || hit->pos.x > ran_x.y + 0.0001)
		is_legit = 0;
	else if (hit->pos.y < ran_y.x - 0.0001 || hit->pos.y > ran_y.y + 0.0001)
		is_legit = 0;
	return (is_legit);
}

int					check_wall_intersection(t_ray ray, t_hit *hit, t_wall *w)
{
	double		det;

	det = ray.matrix.x * w->matrix.y - ray.matrix.y * w->matrix.x;
	if (det > 0.00001 || det < 0.00001)
	{
		hit->pos = (t_vector2d)
			{(ray.matrix.z * w->matrix.y - w->matrix.z * ray.matrix.y) / det,
			(ray.matrix.x * w->matrix.z - ray.matrix.z * w->matrix.x) / det};
		if (check_wall_coherence(ray, w->coord[0], w->coord[1], hit))
			return(1);
	}
	else
		hit->result = 0;
	return (0);
}