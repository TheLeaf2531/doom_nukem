/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:10:27 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/17 20:26:59 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

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
