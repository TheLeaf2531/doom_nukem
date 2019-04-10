/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:21:03 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/10 21:27:15 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

t_map_line					*get_line_elem(t_map_line *start, int i)
{
	t_map_line	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->number == i)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void						free_map_file(t_mapfile *map)
{
	t_map_line	*tmp;
	t_map_line	*tmp_n;
	int			i;

	tmp = map->list;
	if (tmp)
	{
		tmp_n = tmp->next;
		i = 0;
		while (i < tmp->fields_nbr)
		{
			free(tmp->fields[i]);
			i++;
		}
		free(tmp->fields);
		free(tmp);
		tmp = tmp_n;
	}
	free(map);
}

static int					add_line_node(char *line, t_mapfile *map)
{
	t_map_line		*m_line;

	if (!(m_line = ft_memalloc(sizeof(t_map_line))))
		return (0);
	m_line->number = map->line_number;
	m_line->fields_nbr = elem_nbrs(line, '|');
	if (!(m_line->fields = ft_strsplit(line, '|')))
		return (0);
	if (m_line->number == 0)
		map->list = m_line;
	else
	{
		m_line->prev = get_line_elem(map->list, m_line->number - 1);
		if (m_line->prev == NULL)
			return (0);
		m_line->prev->next = m_line;
		m_line->next = NULL;
	}
	return (1);
}

t_mapfile					*generate_mapfile(char *filename)
{
	t_mapfile	*file;
	char		*line;
	int			fd;
	int			gnl_res;

	if ((fd = open(filename, O_RDONLY)) <= 0 ||
		!(file = ft_memalloc(sizeof(t_mapfile))))
	{
		perror("Error");
		return (NULL);
	}
	file->line_number = 0;
	while ((gnl_res = get_next_line(fd, &line)) > 0)
	{
		if (!add_line_node(line, file))
			return (NULL);
		if (file->line_number > 1000)
			return (NULL);
		file->line_number += 1;
		free(line);
	}
	if (gnl_res == -1)
		return (NULL);
	return (file);
}
