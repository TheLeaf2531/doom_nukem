/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:13:19 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/08 20:02:27 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			main(void)
{
	t_environment	*env;

	if (!(env = init_environment((t_vector2i){(int)WIDTH, (int)HEIGHT})))
		return (0);
	game_loop(env);
	return (0);
}