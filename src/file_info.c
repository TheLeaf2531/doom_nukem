/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:00:20 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:04 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			count_sectors(t_mapfile	*file)
{
	int			tmp_sec;
	int			tmp_end;
	t_map_line	*line;

	line = file->list;
	tmp_sec = 0;
	tmp_end = 0;
	while (line)
	{
		if (line->fields[0][0] == 'S')
			tmp_sec++;
		if (line->fields[0][0] == 'E')
			tmp_end++;
		line = line->next;
	}
	if (tmp_sec != tmp_end)
		return (0);
	if (tmp_sec == 0)
		return (0);
	return (tmp_sec);
}

int		count_walls(t_map_line *f_l)
{
	t_map_line	*line;
	int			sector_found;
	int			walls;

	line = f_l;
	sector_found = 0;
	walls = 0;
	while (line)
	{
		if (line->fields[0][0] == 'S')
			sector_found = 1;
		if (sector_found && line->fields[0][0] == 'W')
			walls++;
		if (sector_found && line->fields[0][0] == 'E')
			return (walls);
		line = line->next;
	}
	return (0);
}

int		count_gates(t_map_line *f_l)
{
	t_map_line	*line;
	int			sector_found;
	int			gates;

	line = f_l;
	sector_found = 0;
	gates = 0;
	while (line)
	{
		if (line->fields[0][0] == 'S')
			sector_found = 1;
		if (sector_found && line->fields[0][0] == 'G')
			gates++;
		if (sector_found && line->fields[0][0] == 'E')
			return (gates);
		line = line->next;
	}
	return (0);	
}