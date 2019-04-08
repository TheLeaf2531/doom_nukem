/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:02:22 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/08 20:04:24 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			game_loop(t_environment *e)
{
	while (e->state != QUIT)
	{
		if (e->state == MENU)
		{

		}
		else if (e->state == RUNNING)
		{
			
		}
	}
	return (1);
}