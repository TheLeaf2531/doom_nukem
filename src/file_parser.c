/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:26:16 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/10 21:14:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static int		check_level_name(char *str)
{
	int		elems;
	char	**tab;
	int		i;

	elems = elem_nbrs(str, '.');
	if (elems < 2)
		return (0);
	if (!(tab = ft_strsplit(str, '.')))
		return (0);
	if (ft_strcmp(FILE_EXTENSION, tab[elems - 1]) != 0)
		return (0);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

static t_level			*generate_level(t_mapfile *mapfile)
{
	t_map_line	*line;
	int			i;
	int			y;

	i = 0;
	while (i <= mapfile->line_number)
	{
		y = 0;
		line = get_line_elem(mapfile->list, i);
		while (y < line->fields_nbr)
		{
			printf ("%s ", line->fields[y]);
			y++;
		}
		printf("\n");
		i++;
	}
	return (NULL);
}

t_level			*load_level(char *str)
{
	t_mapfile	*mapfile;
	t_level		*level;

	if (!(check_level_name(str)))
	{
		ft_putstr("Error :Invalid file extension\n");
		return (NULL);
	}
	if (!(mapfile = generate_mapfile(str)))
	{
		ft_putstr("Error :Invalid file\n");
		return (NULL);
	}
	if (!(check_file_fields(mapfile)))
	{
		free_map_file(mapfile);
		ft_putstr("Error :Invalid number of fields\n");
		return (NULL);
	}
	if (!(level = generate_level(mapfile)))
		return (NULL);
	return (level);
}