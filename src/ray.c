/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:25:34 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/19 17:30:49 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

void					set_ray_direction(t_ray *ray, int origin_sector,
							t_vector2d origin, t_vector2d dir)
{
	(*ray).pos = origin;
	(*ray).exluded_wall = -1;
	(*ray).dir = dir;
	(*ray).c_sector = origin_sector;
}

void					set_ray_options(t_ray *ray, int flags, double maximum_distance)
{
	(*ray).flags = flags;
	(*ray).max_dist = maximum_distance;
}
