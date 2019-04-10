/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:15:05 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/10 20:59:28 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static int	check_field(char t, int fields)
{
	if (t == 'T' && fields != FIELD_TEXTURE)
		return (0);
	else if (t == 'K' && fields != FIELD_SKYBOX)
		return (0);
	else if (t == 'S' && fields != FIELD_SECTOR)
		return (0);
	else if (t == 'W' && fields != FIELD_WALL)
		return (0);
	else if (t == 'R' && fields != FIELD_SPRITE)
		return (0);
	else if (t == 'G' && fields != FIELD_GATE)
		return (0);
	else if (t == 'E' && fields != FIELD_ENNEMI)
		return (0);
	else if (t == 'P' && fields != FIELD_PLAYER)
		return (0);
	return (1);
}

int			check_file_fields(t_mapfile *map)
{
	t_map_line		*tmp;

	if (!map->list)
		return (0);
	tmp = map->list;
	while (tmp)
	{
		if (tmp->fields && tmp->fields[0])
		{
			if (!(check_field(tmp->fields[0][0], tmp->fields_nbr)))
				return (0);
		}
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
