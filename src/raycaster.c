/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:29:24 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 20:35:36 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

void					set_ray_direction(t_ray *ray, int origin_sector,
							t_vector2d origin, t_vector2d dir)
{
	(*ray).pos = origin;
	(*ray).dir = origin;
	(*ray).curr_sector = origin_sector;
}

void					set_ray_options(t_ray *ray, int flags, double maximum_distance)
{
	(*ray).flags = flags;
	(*ray).max_dist = maximum_distance;
}

t_hit					*cast_ray(t_ray ray)
{
	t_hit		*final_hitlist;
	t_hit		*tmp_hit;

	final_hitlist = init_hit(NULL);
	return (hit);
}
