/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_equ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:07:12 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 21:56:15 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static void calc_matrix(t_vector3d *matrix, t_vector2d s, t_vector2d e)
{
	matrix->x = (e.y - s.y) / (e.x - s.x);
	matrix->y = -1.0;
	matrix->z = (s.y - matrix->x * s.x);
	if (matrix->z != 0)
		matrix->z *= -1.0;
	if (fabs(s.x - e.x) < 0.00001)
	{
		matrix->x = 1.0;
		matrix->y = 0.0;
		matrix->z = s.x;
	}
}

static void precalc_walls_matrix(t_level *level)
{
	int c_sec;
	int c_wall;

	c_sec = 0;
	while (c_sec < level->sectors)
	{
		c_wall = 0;
		while (c_wall < level->sector[c_sec]->walls)
		{
			calc_matrix(&(level->sector[c_sec]->wall[c_wall]->matrix),
				level->sector[c_sec]->wall[c_wall]->coord[0],
				level->sector[c_sec]->wall[c_wall]->coord[1]);
			//t_wall	*w = level->sector[c_sec]->wall[c_wall];
			//printf ("Wall matrix [%f;%f;%f]\n", w->matrix.x, w->matrix.y, w->matrix.z);
			c_wall++;
		}
		//printf ("\n\n");
		c_sec++;
	}
}

void		precalc_static_matrix(t_level *level)
{
	precalc_walls_matrix(level);
}