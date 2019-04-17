/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:45:32 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 17:43:32 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

void		printf_level(t_level *level)
{
	t_vector3i swg;

	swg = (t_vector3i) {0,0,0};
	while (swg.x < level->sectors)
	{
		printf ("\n\nSector : %d\n", swg.x);
		printf ("Info : \n");
		printf ("	Id    : %d\n", level->sector[swg.x]->id);
		printf ("	Ceil  : %f\n", level->sector[swg.x]->ceil);
		printf ("	Floor : %f\n", level->sector[swg.x]->floor);
		printf ("	Gates : %d\n", level->sector[swg.x]->gates);
		printf ("	Walls : %d\n", level->sector[swg.x]->walls);
		swg.y = 0;
		swg.z = 0;
		printf ("List of walls :\n");
		while (swg.y < level->sector[swg.x]->walls)
		{
			printf("\n	Wall %d\n", swg.y);
			printf("		Starting coord    : {%f;%f}\n",level->sector[swg.x]->wall[swg.y]->coord[0].x, level->sector[swg.x]->wall[swg.y]->coord[0].y);
			printf("		End      coord    : {%f;%f}\n",level->sector[swg.x]->wall[swg.y]->coord[1].x, level->sector[swg.x]->wall[swg.y]->coord[1].y);
			printf("		is_gate           : %d\n", level->sector[swg.x]->wall[swg.y]->is_gate);
			printf("		collider          : %d\n", level->sector[swg.x]->wall[swg.y]->collider);
			printf("		texture_id        : %d\n", level->sector[swg.x]->wall[swg.y]->texture_id);
			printf("		is_window         : %d\n", level->sector[swg.x]->wall[swg.y]->is_window);
			printf("		texture_id_closed : %d\n", level->sector[swg.x]->wall[swg.y]->close_texture_id);
			swg.y++;
		}
		printf ("\nList of gates :\n");
		while (swg.z < level->sector[swg.x]->gates)
		{
			printf("\n	Gate : %d\n", swg.z);
			printf("		entry           : %d\n", level->sector[swg.x]->gate[swg.z]->sector_1);
			printf("		exit            : %d\n", level->sector[swg.x]->gate[swg.z]->sector_2);
			swg.z++;
		}
		swg.x++;
	}
}