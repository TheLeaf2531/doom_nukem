/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:05:29 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/19 16:01:52 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static int			fill_gate(t_vector3i swg, t_level *level, t_gate *gate,
						t_map_line *line)
{
	gate->sector_1 = swg.x;
	gate->sector_2 = ft_atoi(line->fields[2]);
	if (!(level->sector[gate->sector_2]) ||
			!(level->sector[gate->sector_2]->wall[ft_atoi(line->fields[3])]))
		return (0);
	if (!(level->sector[swg.x]->wall[ft_atoi(line->fields[1])]))
		return (0);
	gate->wall_1 = level->sector[swg.x]->wall[ft_atoi(line->fields[1])];
	gate->wall_1->gate = gate;
	gate->wall_2 = level->sector[gate->sector_2]->wall[ft_atoi(line->fields[3])];
	return (1);
}

static void			fill_wall(int id, t_wall *wall, t_map_line *line, t_sector *s)
{
	wall->coord[0] = (t_vector2d){(double)ft_atof(line->fields[1]),
									(double)ft_atof(line->fields[2])};
	wall->coord[1] = (t_vector2d){(double)ft_atof(line->fields[3]),
									(double)ft_atof(line->fields[4])};
	wall->id = id;
	wall->collider = ft_atoi(line->fields[5]);
	wall->is_gate = ft_atoi(line->fields[6]);
	wall->is_closed = ft_atoi(line->fields[7]);
	wall->is_window = ft_atoi(line->fields[8]);
	wall->sector = s;
	wall->texture_id = ft_atoi(line->fields[9]);
	wall->close_texture_id = ft_atoi(line->fields[10]);
}

int					fill_level(t_level *level, t_mapfile *file)
{
	t_map_line	*line;
	t_vector3i	swg;

	swg = (t_vector3i) {0, 0, 0};
	line = file->list;
	while (line)
	{
		if (line->fields[0][0] == 'W')
		{
			fill_wall(swg.y, level->sector[swg.x]->wall[swg.y], line, level->sector[swg.x]);
			swg.y++;
		}
		if (line->fields[0][0] == 'G')
		{
			if (!(fill_gate(swg, level, level->sector[swg.x]->gate[swg.z], line)))
				return (0);
			swg.z++;
		}
		if (line->fields[0][0] == 'E')
			swg = (t_vector3i) {swg.x + 1, 0 , 0};
		line = line->next;
	}
	return (1);
}