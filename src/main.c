/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:13:19 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/02 16:45:49 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

typedef struct		s_vector3d
{
	double x;
	double y;
	double z;
}					t_vector3d;

typedef struct		s_vector2d
{
	double x;
	double y;
}					t_vector2d;

static void		render_test(void)
{
	t_vector3d	pos;
	t_vector3d	wall_pos[4];

	pos = (t_vector3d) {2.0, 2.0 ,1.0};
	wall_pos[0] = (t_vector3d) {0.0,0.0,0.0};
	wall_pos[1] = (t_vector3d) {3.0,0.0,0.0};
	wall_pos[2] = (t_vector3d) {3.0,3.0,1.0};
	wall_pos[3] = (t_vector3d) {0.0,3.0,1.0};
	
}

int			main(void)
{
	return (0);
}