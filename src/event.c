/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:34:31 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/08 20:05:12 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static void		keyboard_event(t_environment *e, SDL_Event ev)
{
	if (ev.type == SDL_KEYUP)
	{
		if (ev.key.keysym.sym == SDLK_ESCAPE)
			e->state = QUIT;
	}
}

void			update_event(t_environment *e)
{
	SDL_Event	ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
			keyboard_event(e, ev);
	}
}