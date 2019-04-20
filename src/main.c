/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:13:19 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 21:55:43 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			main(int argc, char **argv)
{
	t_environment	*env;

	if (argc != 2)
	{
		ft_putstr("Usage : TODO\n");
		return (0);
	}
	if (!(env = init_environment((t_vector2i){(int)WIDTH, (int)HEIGHT})))
		return (0);
	if (!(env->level = load_level(argv[1])))
		return (0);
	//TODO : Check level coherence convex_sector, gate well_linked, set links
	// TEST
	/*
	t_hit					hit;
	t_ray					ray;
	hit.result = 0;
	hit.distance = 0;
	precalc_static_matrix(env->level);
	set_ray_direction(&ray, 0, (t_vector2d){2,1}, (t_vector2d){0, 1});
	set_ray_options(&ray, RAYCAST_WALLS, 20);
	cast_ray(ray, &hit, env->level);
	printf ("hit result %d, distance uncorrected : %f\n", hit.result, hit.distance);
	printf ("{%f;%f}\n", hit.pos.x, hit.pos.y);
	if (hit.type == 1)
		printf ("it's a gate\n");
	if (hit.type == 2)
		printf ("it's a wall\n");
	else 
		printf ("it's the devil, don't hit it !\n");*/
	// STOP TEST
	game_loop(env);
	return (0);
}
