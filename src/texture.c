/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:13:04 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/09 21:01:30 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

SDL_Texture		*fill_texture(SDL_Texture **tex, Uint32 c)
{
	t_vector2i	coord;
	t_vector2i	size;
	int			pitch;
	Uint32		*pixels;
	
	if ((SDL_LockTexture(*tex, NULL, (void**)&pixels, &pitch) == -1) ||
		SDL_QueryTexture((*tex), NULL, NULL, &(size.x), &(size.y)) == -1)
	{
		ft_putstr(SDL_GetError());
		return (NULL);
	}
	printf ("Size texture : %d %d\n", size.x, size.y);
	coord = (t_vector2i) {(int)0, (int)0};
	while (coord.y < size.y)
	{
		coord.x = 0;
		while (coord.x < size.x)
		{
			(pixels[size.x * coord.y + coord.x]) = c;
			coord.x++;
		}
		coord.y++;
	}
	printf ("coord %d %d\n", coord.x, coord.y);
	SDL_UnlockTexture((*tex));
	return ((*tex));
}

SDL_Texture		*resize_texture(t_environment *e, SDL_Texture **tex)
{
	SDL_DestroyTexture((*tex));
	if (!((*tex) = create_texture(e, tex)))
		return (NULL);
	return ((*tex));
}

SDL_Texture		*create_texture(t_environment *e, SDL_Texture **tex)
{
	SDL_PixelFormat	*format;
	int				w;
	int				h;
	
	SDL_GetWindowSize(e->window, &w, &h);
	if (!((*tex) = SDL_CreateTexture(e->renderer,
			SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING,
			w,
			h)))
	{
		perror(SDL_GetError());
		return (NULL);
	}
	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	fill_texture(tex, SDL_MapRGBA(format, 100, 100, 100, 255));
	SDL_FreeFormat(format);
	return ((*tex));
}

SDL_Texture		*get_fsdl_texture(t_environment	*e, SDL_Texture **tex)
{
	if (!(*tex))
	{
		if (!((*tex) = create_texture(e, tex)))
			return (NULL);
	}
	else
	{
		if (e->win_ev.size_changed)
			if (!(resize_texture(e, tex)))
				return (NULL);
	}
	return ((*tex));
}