/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_exit_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:32:43 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:30:47 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_openexit_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	width = 32;
	height = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/Exit/ExitOpen.xpm", &width, &height);
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

void	set_exit_sprite(t_engine *eng, int i, int j)
{
	char	*text_pixel;
	int		x;
	int		y;
	int		height;
	int		width;

	width = 32;
	height = 32;
	eng->sprite->img_ptr = mlx_xpm_file_to_image(eng->final_img->mlx_ptr,
			"./textures/Exit/ExitClose.xpm", &width, &height);
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

void	find_and_replace_openexit_sprite(t_engine *engine)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	i = 0;
	x_pos = 0;
	while (engine->map->map[i] != NULL)
	{
		j = 0;
		y_pos = 0;
		while (engine->map->map[i][j] != '\0')
		{
			if (engine->map->map[i][j] == 'E')
				set_openexit_sprite(engine, y_pos, x_pos);
			y_pos = y_pos + 32;
			j++;
		}
		x_pos = x_pos + 32;
		i++;
	}
}
