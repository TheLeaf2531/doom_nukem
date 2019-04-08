/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:10:27 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/04 18:25:06 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

void		free_hit_list(t_hit	*start)
{
	t_hit	*next;

	while (start)
	{
		next = start->next;
		free(start);
		start = next;
	}
}

t_hit		*init_hit(t_hit		*previous_hit)
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