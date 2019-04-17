/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:26:16 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 17:50:08 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static int				check_level_name(char *str)
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

static int				fill_sectors(t_mapfile *mapfile, t_level *level)
{
	t_map_line		*line;
	int				s;

	line = mapfile->list;
	s = 0;
	while (line)
	{
		if (line->fields[0][0] == 'S')
		{
			level->sector[s]->id = ft_atoi(line->fields[1]);
			if (level->sector[s]->id != s)
				return (0);
			level->sector[s]->ceil = ft_atof(line->fields[2]);
			level->sector[s]->ceil = ft_atof(line->fields[3]);
			s++;
		}
		line = line->next;
	}
	return (1);
}

static t_level			*generate_level(t_mapfile *mapfile)
{
	t_level		*level;

	if (!(level = ft_memalloc(sizeof(t_level))))
		return (NULL);
	printf("Do the thing  !\n");
	if (!(allocate_sectors(level, mapfile)))
		return (NULL);
	printf("Do it !\n");	
	if (!(fill_sectors(mapfile, level)))
		return (NULL);
	printf("Do the FUCKING THING !\n");	
	if (!(fill_level(level, mapfile)))
		return (NULL);
	printf("Doooooooooooooo it!\n");	
	printf_level(level);
	return (level);	
}

t_level					*load_level(char *str)
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
