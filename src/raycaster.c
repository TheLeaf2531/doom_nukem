/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:29:24 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/11 00:57:43 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static t_ray			create_ray(t_vector2d start, t_vector2d direction,
							int sector_start)
{
	t_ray		ray;

	ray.pos = start;
	ray.dir = direction;
	ray.curr_sector = sector_start;
	return (ray);
}

t_hit					*raycast(t_ray ray, int flags)
{
}
