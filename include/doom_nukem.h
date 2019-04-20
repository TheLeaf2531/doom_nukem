/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:11:48 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/19 21:21:28 by vboissel         ###   ########.fr       */
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
# define RAYCAST_SPRITES  4
# define RAYCAST_WINDOWS  8

# define FILE_EXTENSION "dnmap"

# define FIELD_TEXTURE 3
# define FIELD_WEAPON  9
# define FIELD_KEY	   4
# define FIELD_SKYBOX  5
# define FIELD_SECTOR  4
# define FIELD_WALL    11
# define FIELD_SPRITE  11
# define FIELD_GATE    4
# define FIELD_ZONE    4
# define FIELD_OBJECT  6
# define FIELD_ENNEMI  6
# define FIELD_PLAYER  7
# define FIELD_ACTION  3
# define FIELD_TEVENTS 3
# define FIELD_END	   1

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
int						count_sectors(t_mapfile	*file);
int						count_walls(t_map_line *f_l);
int						allocate_sectors(t_level *level, t_mapfile *file);
int						count_gates(t_map_line *f_l);
void					printf_level(t_level *level);
void					printf_ray(t_ray ray);
int						fill_level(t_level *level, t_mapfile *file);
t_hit					*init_hit(t_hit *previous_hit);
void					free_hit_list(t_hit *start);
void					precalc_static_matrix(t_level *level);
int						check_wall_intersection(t_ray ray, t_hit *hit, t_wall *w);
void					cast_ray(t_ray ray, t_hit *hit, t_level *level);
void					set_ray_direction(t_ray *ray, int origin_sector,
							t_vector2d origin, t_vector2d dir);
void					set_ray_options(t_ray *ray, int flags, double maximum_distance);
t_hit					*get_hit_buffer(t_environment *e, t_hit **hit_buffer);
void					clear_hit_buffer(int buffer_size, t_hit **hit_buffer);

#endif
