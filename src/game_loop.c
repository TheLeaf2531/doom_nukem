/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:02:22 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/11 17:15:51 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			game_loop(t_environment *e)
{
	while (e->state != QUIT)
	{
		e->time.s = SDL_GetTicks();
		if (e->state == MENU)
		{
		}
		else if (e->state == RUNNING)
		{
			update_event_ingame(e);
			if (!(render_frame(e)))
				return (0);
		}
		e->time.e = SDL_GetTicks();
		e->time.delta_time = (float)(e->time.e - e->time.s) / 1000.0F;
		printf("DeltaTime : %f\n", e->time.delta_time);
	}
	return (1);
}
