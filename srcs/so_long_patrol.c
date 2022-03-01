/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:57:47 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:39:20 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_ennemy_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	height = 32;
	width = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/ennemy/ennemy.xpm", &width, &height);
	eng->sprite->addr = mlx_get_data_addr(eng->sprite->img_ptr, &eng->sprite
			->bits_per_pixel, &eng->sprite->line_length, &eng->sprite->endian);
	y = 0;
	while (y++ < 32)
	{
		x = 0;
		while (x++ < 32)
		{
			text_pixel = eng->sprite->addr + (y * eng->sprite->line_length
					+ x * (eng->sprite->bits_per_pixel / 8));
			if (text_pixel[0] != 0 && text_pixel[1] != 0 && text_pixel[2] != 0)
				my_mlx_pixel_put(eng->final_img, x + i, y + j, text_pixel);
		}
	}
	free_image(eng);
}

void	set_alerted_guard_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	height = 32;
	width = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/ennemy/ennemy2.xpm", &width, &height);
	eng->sprite->addr = mlx_get_data_addr(eng->sprite->img_ptr, &eng->sprite
			->bits_per_pixel, &eng->sprite->line_length, &eng->sprite->endian);
	y = 0;
	while (y++ < 32)
	{
		x = 0;
		while (x++ < 32)
		{
			text_pixel = eng->sprite->addr + (y * eng->sprite->line_length
					+ x * (eng->sprite->bits_per_pixel / 8));
			if (text_pixel[0] != 0 && text_pixel[1] != 0 && text_pixel[2] != 0)
				my_mlx_pixel_put(eng->final_img, x + i, y + j, text_pixel);
		}
	}
	free_image(eng);
}

void	patrol_move_up(t_engine *engine, int x, int y)
{
	if (engine->map->map[x - 1][y + 1] == 'P')
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x - 1][y] = 'M';
		set_alerted_guard_sprite(engine, y * 32, (x - 1) * 32);
	}
	else if (engine->map->map[x - 1][y - 1] == 'P')
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x - 1][y] = 'M';
		set_alerted_guard_sprite(engine, y * 32, (x - 1) * 32);
	}
	else
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x - 1][y] = 'M';
		set_ennemy_sprite(engine, y * 32, (x - 1) * 32);
	}
}

void	patrol_move_down(t_engine *engine, int x, int y)
{
	if (engine->map->map[x + 1][y + 1] == 'P')
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x + 1][y] = 'M';
		set_alerted_guard_sprite(engine, y * 32, (x + 1) * 32);
	}
	else if (engine->map->map[x + 1][y - 1] == 'P')
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x + 1][y] = 'M';
		set_alerted_guard_sprite(engine, y * 32, (x + 1) * 32);
	}
	else
	{
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
		engine->map->map[x + 1][y] = 'M';
		set_ennemy_sprite(engine, y * 32, (x + 1) * 32);
	}
}
