/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:15:15 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:23 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static int		allocate_walls(t_level *level, int i, t_map_line *line)
{
	t_map_line	*l;
	int			y;

	l = line;
	if (!(level->sector[i]->walls = count_walls(l)))
				return (0);
	if (!(level->sector[i]->wall = ft_memalloc(sizeof(t_wall)
				* level->sector[i]->walls)))
		return (0);
	y = 0;
	while (line)
	{
		if (line->fields[0][0] == 'W')
		{
			if (!(level->sector[i]->wall[y] = ft_memalloc(sizeof(t_wall))))
				return (0);
			y++;
		}
		if (line->fields[0][0] == 'E')
			return (1);
		line = line->next;
	}
	return (0);
}

static int	allocate_gates(t_level *level, int i,  t_map_line *line)
{
	int			y;

	level->sector[i]->gates = count_gates(line);
	if (level->sector[i]->gates > 0)
	{
		if (!(level->sector[i]->gate = ft_memalloc(sizeof(t_gate*) *
			level->sector[i]->gates)))
			return (0);
	}
	y = 0;
	while (line)
	{
		if (line->fields[0][0] == 'G')
		{
			if (!(level->sector[i]->gate[y] = ft_memalloc(sizeof(t_gate))))
				return (0);
			y++;
		}
		if (line->fields[0][0] == 'E')
			return (1);
		line = line->next;
	}
	return (1);
}

int			allocate_sectors(t_level *level, t_mapfile *file)
{
	int			i;
	t_map_line	*line;

	i = 0;
	if ((level->sectors = count_sectors(file)) == 0)
		return (0);
	if (!(level->sector = ft_memalloc(sizeof(t_sector*) * level->sectors)))
		return (0);	
	line = file->list;
	while (line)
	{
		if (line->fields[0][0] == 'S')
		{
			if (!(level->sector[i] = ft_memalloc(sizeof(t_sector))))
				return (0);
			if (!(allocate_walls(level, i, line)) || !(allocate_gates(level, i, line)))
				return (0);
		}
		if (line->fields[0][0] == 'E')
			i++;
		line = line->next;
	}
	return (i != level->sectors ? 0 : 1);
}