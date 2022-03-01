/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:29:41 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:03:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_keycode(int keycode, t_img *final_img)
{
	if (keycode == W_KEY)
		final_img->keycode = 'w';
	else if (keycode == A_KEY)
		final_img->keycode = 'a';
	else if (keycode == S_KEY)
		final_img->keycode = 's';
	else if (keycode == D_KEY)
		final_img->keycode = 'd';
	else if (keycode == F_KEY)
		final_img->keycode = 'f';
	else if (keycode == ESC_KEY)
		final_img->keycode = 'e';
	else
	{
		final_img->keycode = '0';
		return (SUCCESS);
	}
	return (ERROR);
}

void	set_bonus_utils_value(t_engine *engine)
{
	engine->sprite->sprite_anim = 0;
	engine->sprite->sprite_anim_ennemy = 0;
	engine->map->move_count = 0;
}

int	close_window(t_engine *engine)
{
	free_engine(engine);
	exit(EXIT_SUCCESS);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_engine	*eng;

	eng = NULL;
	eng = malloc_engine(eng);
	if (eng == NULL)
		exit(EXIT_FAILURE);
	if (arg_check(argc, argv[1], eng) == ERROR)
		exit (EXIT_FAILURE);
	eng->final_img->mlx_ptr = mlx_init();
	eng->final_img->win_ptr = mlx_new_window(eng->final_img->mlx_ptr,
			(eng->map->column_nbr * 32), (eng->map->line_nbr * 32), "so_long");
	eng->final_img->img_ptr = mlx_new_image(eng->final_img->mlx_ptr,
			(eng->map->column_nbr * 32), (eng->map->line_nbr * 32));
	eng->final_img->addr = mlx_get_data_addr(eng->final_img->img_ptr,
			&(eng->final_img->bits_per_pixel), &(eng->final_img->line_length),
			&(eng->final_img->endian));
	mlx_key_hook(eng->final_img->win_ptr, set_keycode, eng->final_img);
	mlx_hook(eng->final_img->win_ptr, 17, 1L << 17, close_window, eng);
	if (BONUS == 1)
		set_bonus_utils_value(eng);
	put_whole_map(eng);
	mlx_loop_hook(eng->final_img->mlx_ptr, render_next_frame, eng);
	mlx_loop(eng->final_img->mlx_ptr);
	return (SUCCESS);
}
