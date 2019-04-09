/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:06:08 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/09 20:50:50 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int				render_frame(t_environment *e)
{
	static SDL_Texture		*tex;

	if (!tex || e->win_ev.size_changed)
	{	
		printf("Sans deconner\n");
		if (!(tex = get_fsdl_texture(e, &tex)))
			return (0);
	}
	if (SDL_RenderClear(e->renderer) == -1)
	{
		ft_putstr(SDL_GetError());
		return (0);
	}
	//Calculation here
	
	if (SDL_RenderCopy(e->renderer, tex, NULL, NULL) == -1)
	{
		perror(SDL_GetError());
		return (0);
	}
	SDL_RenderPresent(e->renderer);
	return (1);
}