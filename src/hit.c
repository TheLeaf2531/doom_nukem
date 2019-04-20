/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:10:27 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 21:58:02 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

void		clear_hit_buffer(int buffer_size, t_hit **hit_buffer)
{
	int		i;

	i = 0;
	while (i < buffer_size)
	{
		(*hit_buffer)[i].result = 0;
		(*hit_buffer)[i].pos = (t_vector2d) {0, 0};
		(*hit_buffer)[i].distance = 0;
		(*hit_buffer)[i].sector = 0;
		(*hit_buffer)[i].type = 0;
		(*hit_buffer)[i].target = NULL;
		i++;
	}
}

static int			init_hit_buffer(t_environment *e, t_hit	**hit_buffer)
{
	int				w;
	int				h;

	SDL_GetWindowSize(e->window, &w, &h);
	if (!((*hit_buffer) = ft_memalloc(sizeof(t_hit) * w * h)))
	{
		perror("Error : ");
		return (0);
	}
	clear_hit_buffer(w * h, hit_buffer);
	return (1);
}

t_hit				*get_hit_buffer(t_environment *e, t_hit **hit_buffer)
{
	if (!(*hit_buffer))
	{
		if (!(init_hit_buffer(e, hit_buffer)))
			return (NULL);
	}
	else
	{
		if (e->win_ev.size_changed)
		{
			ft_memdel((void**)hit_buffer);
			if (!(init_hit_buffer(e, hit_buffer)))
				return (NULL);
		}
	}
	return (*hit_buffer);
}

/*
void		free_hit_list(t_hit *start)
{
	t_hit	*next;

	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}

void		add_hit(t_hit *hitlist, t_hit *new_hit)
{
	t_hit	*tmp;
	int		searching;

	tmp = hitlist;
	searching = 1;
	while (tmp && searching)
	{
		if (tmp->distance < new_hit->distance)
		{
			tmp->prev->next = new_hit;
			new_hit->prev = tmp->prev;
			new_hit->next = new_hit->prev->next;
			new_hit->next->prev = new_hit;
			new_hit->prev->next = new_hit;
			searching = 0;
		}
		tmp = tmp->next;
	}
}

t_hit		*init_hit(t_hit *previous_hit)
{
	t_hit		*hit;

	if (!(hit = ft_memalloc(sizeof(t_hit))))
		return (NULL);
	if (previous_hit)
	{
		previous_hit->next = hit;
		hit->prev = previous_hit;
	}
	return (hit);
}
*/