/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_sprite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:17:22 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:31:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	height = 32;
	width = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/player/Player.xpm", &width, &height);
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

void	set_player_firing_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	height = 32;
	width = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/player/Player2.xpm", &width, &height);
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
