/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:18:55 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/08 18:25:52 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

static SDL_Window			*create_window(t_vector2i size)
{
	SDL_Window	*w;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		perror(SDL_GetError());
		return (NULL);
	}
	if (!(w = SDL_CreateWindow("WOLF_3D", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					size.x,
					size.y,
					SDL_WINDOW_SHOWN)))
	{
		perror(SDL_GetError());
		return (NULL);
	}
	return (w);
}

static SDL_Renderer			*create_renderer(SDL_Window *window)
{
	SDL_Renderer	*renderer;

	if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)))
	{
		perror(SDL_GetError());
		ft_putstr("trying to switch to : SDL_RENDERER_SOFTWARE\n");
		if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE)))
		{
			perror(SDL_GetError());
			return (NULL);
		}
	}
	return (renderer);
}

t_environment				*init_environment(t_vector2i window_size)
{
	t_environment	*env;

	if (!(env = ft_memalloc(sizeof(t_environment))))
		return (NULL);
	if (!(env->window = create_window(window_size)))
		return (NULL);
	if (!(env->renderer = create_renderer(env->window)))
		return (NULL);
	env->state = RUNNING;
	return (env);
}
