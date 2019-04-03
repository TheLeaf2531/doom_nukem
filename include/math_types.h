/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:30:20 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/03 16:35:00 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_TYPES_H
# define MATH_TYPES_H

typedef struct		s_vector2i
{
	int			x;
	int			y;
}					t_vector2i;

typedef struct		s_vector2f
{
	float		x;
	float		y;
}					t_vector2f;

typedef struct		s_vector2d
{
	double		x;
	double		y;
}					t_vector2d;

typedef struct		s_vector3i
{
	int			x;
	int			y;
	int			z;
}					t_vector2i;

typedef struct		s_vector3f
{
	float		x;
	float		y;
	float		z;
}					t_vector3f;

typedef struct		s_vector3d
{
	double		x;
	double		y;
	double		z;
}					t_vector3d;

#endif