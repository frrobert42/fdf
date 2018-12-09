/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:31:15 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/09 15:13:49 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, t_env *env)
{
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (key == 78 || key == 69)
		ft_key_zooming(key, env);
	else if (key == R_KEY || key == G_KEY || key == B_KEY || key == I_KEY)
		ft_key_color(key, env);
	else if (key == LEFT_KEY || key == RIGHT_KEY || key == DOWN_KEY ||
				key == UP_KEY)
		ft_key_move(key, env);
	else if (key == SP_KEY)
		ft_key_position(env);
	else if (key == A_KEY || key == Z_KEY)
		ft_key_alt(key, env);
	ft_expose_hook(env);
	return (0);
}

int		ft_expose_hook(t_env *env)
{
	env->img.ptr = mlx_new_image(env->ptr, WIN_WIDTH, WIN_HEIGHT);
	env->img.data = mlx_get_data_addr(env->img.ptr, &(env->img.bpp),
			&(env->img.size_l), &(env->img.endian));
	draw(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img.ptr, 0, 0);
	menu(env);
	mlx_destroy_image(env->ptr, env->img.ptr);
	return (0);
}
