/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_nukem.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:11:48 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/08 20:04:20 by vboissel         ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1080
# define NO_FLAG 0
# define RAYCAST_WALLS 1
# define RAYCAST_GATES 2
# define RAYCAST_ENNEMIES 4
# define RAYCAST_WINDOWS 8

t_environment			*init_environment(t_vector2i window_size);
int						game_loop(t_environment *e);
void					update_event(t_environment *e);

#endif