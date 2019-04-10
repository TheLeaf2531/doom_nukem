/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:11:48 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/10 21:19:45 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_NUKEM_H
# define DOOM_NUKEM_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <SDL2/SDL.h>
# include "../libft/libft.h"
# include "math_types.h"
# include "types.h"

# define WIDTH  1920
# define HEIGHT 1080

# define NO_FLAG          0
# define RAYCAST_WALLS    1
# define RAYCAST_GATES    2
# define RAYCAST_ENNEMIES 4
# define RAYCAST_WINDOWS  8

# define FILE_EXTENSION "dnmap"

# define FIELD_TEXTURE 3
# define FIELD_SKYBOX  5
# define FIELD_SECTOR  4
# define FIELD_WALL    9
# define FIELD_SPRITE  9
# define FIELD_GATE    5
# define FIELD_ENNEMI  6
# define FIELD_PLAYER  7

t_environment			*init_environment(t_vector2i window_size);
int						game_loop(t_environment *e);
void					update_event_ingame(t_environment *e);
void					update_event_menu(t_environment *e);
void					set_window_size(SDL_Window *w, t_vector2i size);
int						render_frame(t_environment *e);
SDL_Texture				*resize_texture(t_environment *e, SDL_Texture **tex);
SDL_Texture				*create_texture(t_environment *e, SDL_Texture **tex);
SDL_Texture				*get_fsdl_texture(t_environment	*e, SDL_Texture **tex);
SDL_Texture				*fill_texture(SDL_Texture **tex, Uint32 c);
int						elem_nbrs(char const *s, char c);
t_mapfile				*generate_mapfile(char *filename);
t_map_line				*get_line_elem(t_map_line *start, int i);
void					free_map_file(t_mapfile *map);
int						check_file_fields(t_mapfile *map);
t_level					*load_level(char *str);


#endif
