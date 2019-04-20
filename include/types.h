/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:33:07 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/20 21:35:07 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "math_types.h"

typedef struct		s_map_line
{
	int					number;
	char				**fields;
	int					fields_nbr;
	struct s_map_line	*prev;
	struct s_map_line	*next;
}					t_map_line;

typedef	struct		s_mapfile
{
	int				sector_count;
	int				gate_count;
	int				line_number;
	t_map_line		*list;
}					t_mapfile;

typedef struct		s_player
{
	t_vector2d		pos;
	double			z;
	t_vector2d		rot;
	t_vector2d		plane;
	float			velocity;
	void			*cur_sector;
	int				sec_id;
	double			dist_plane;
}					t_player;

typedef struct		s_sprite
{
	t_vector2d		coord[2];
	t_vector3d		equ;
	int				id;
	int				has_collider;
	double			height;
}					t_sprite;

typedef struct		s_wall
{
	t_vector2d		coord[2];
	t_vector3d		matrix;
	int				id;
	int				type;
	int				texture_id;
	int				close_texture_id;
	int				collider;
	int				is_gate;
	int				is_closed;
	int				is_window;
	void			*gate;
	struct s_sector	*sector;
}					t_wall;

typedef	struct		s_gate
{
	t_wall			*wall_1;
	t_wall			*wall_2;
	int				sector_1;
	int				sector_2;
}					t_gate;

typedef struct		s_sector
{
	int				id;
	int				walls;
	int				gates;
	t_wall			**wall;
	t_gate			**gate;
	double			floor;
	double			ceil;
}					t_sector;

typedef struct			s_texture
{
	t_vector2i		s;
	SDL_Texture		*tex;
	void			*tmp;
	Uint32			*pixels;
	SDL_PixelFormat *format;
	int				pitch;
}						t_texture;

typedef struct		s_level
{
	int				sectors;
	t_sector		**sector;
	int				gates;
}					t_level;

typedef struct		s_hit
{
	t_vector2d		pos;
	t_sector		*sector;
	int				type;
	double			distance;
	void			*target;
	int				result;
}					t_hit;

typedef struct		s_ignore
{
	int				object_type;
	int				object_sector;
	int				object_id;
	struct s_ignore	*prev;
	struct s_ignore	*next;
}					t_ignore;

typedef struct		s_ray
{
	t_vector2d		pos;
	t_vector2d		dir;
	t_vector3d		matrix;
	int 			exluded_wall;
	int				c_sector;
	int				flags;
	int				c_flag;
	int				max_dist;
}					t_ray;

typedef enum		e_gamestate
{
		MENU,
		RUNNING,
		QUIT
}					t_gamestate;

typedef struct		s_window_event
{
	int				size_changed;
}					t_window_event;

typedef struct		s_time
{
	Uint32		s;
	Uint32		e;
	float		delta_time;
}					t_time;

typedef struct		s_renderer_env
{
	t_vector2i	c;
	t_vector2i	size;
	Uint32		*p;
	t_hit		*hit;
	t_ray		ray;
}					t_renderer_env;

typedef struct		s_environment
{
	t_gamestate		state;
	SDL_Window		*window;
	t_window_event	win_ev;
	SDL_Renderer	*renderer;
	t_time			time;
	t_level			*level;
	t_player		player;
}					t_environment;

#endif