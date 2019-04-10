/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:13:19 by vboissel          #+#    #+#             */
/*   Updated: 2019/04/10 21:17:36 by vboissel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doom_nukem.h"

int			main(int argc, char **argv)
{
	t_environment	*env;
	t_level			*level;

	if (argc != 2)
	{
		ft_putstr("Usage : TODO\n");
		return (0);
	}
	if (!(env = init_environment((t_vector2i){(int)WIDTH, (int)HEIGHT})))
		return (0);
	level = load_level(argv[1]);
	//game_loop(env);
	return (0);
}