/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 17:46:07 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/11 00:57:25 by vboissel         ###   ########.fr       */
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

void			update_event_menu(t_environment *e)
{
	SDL_Event	ev;

	while (SDL_PollEvent(&ev))
	{
		if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
			keyboard_event(e, ev);
		if (ev.type == SDL_QUIT)
			e->state = QUIT;
	}
}
