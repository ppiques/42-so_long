/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:31:59 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/21 17:30:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	square_right(t_mlx *mlx)
{
	int count_x;
	int count_y;

	count_y = -1;
	if (mlx->pos.middle == 1)
	{
		printf("Moved square right!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 450 && count_x <= 550 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0x00FF2575;
			}
		}
		mlx->pos.middle = 0;
		mlx->pos.right = 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
	else if (mlx->pos.left == 1)
	{
		printf("Moved square right!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 250 && count_x <= 350 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0xFF0000;
			}
		}
		mlx->pos.middle = 1;
		mlx->pos.left = 0;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
}

int	square_left(t_mlx *mlx)
{
	int count_x;
	int count_y;

	count_y = -1;

	if (mlx->pos.middle == 1)
	{
		printf("Moved square left!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 250 && count_x <= 350 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0x002575FF;
			}
		}
		mlx->pos.middle = 0;
		mlx->pos.left = 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
	else if (mlx->pos.right == 1)
	{
		printf("Moved square left!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 450 && count_x <= 550 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0xFF0000;
			}
		}
		mlx->pos.middle = 1;
		mlx->pos.right = 0;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
}

int	square_up(t_mlx *mlx)
{
	int count_x;
	int count_y;

	count_y = -1;

	if (mlx->pos.middle == 1)
	{
		printf("Moved square up!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 150 && count_y <= 250)
					mlx->img.data[count_y * 800 + count_x] = 0x0010FF90;
			}
		}
		mlx->pos.middle = 0;
		mlx->pos.up = 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
	else if (mlx->pos.down == 1)
	{
		printf("Moved square up!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 350 && count_y <= 450)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0xFF0000;
			}
		}
		mlx->pos.middle = 1;
		mlx->pos.down = 0;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
}

int	square_down(t_mlx *mlx)
{
	int count_x;
	int count_y;

	count_y = -1;

	if (mlx->pos.middle == 1)
	{
		printf("Moved square down!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 350 && count_y <= 450)
					mlx->img.data[count_y * 800 + count_x] = 0x009010FF;
			}
		}
		mlx->pos.middle = 0;
		mlx->pos.down = 1;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
	else if (mlx->pos.up == 1)
	{
		printf("Moved square down!\n");
		while(++count_y < 600)
		{
			count_x = -1;
			while (++count_x < 800)
			{
				if (count_x >= 350 && count_x <= 450 && count_y >= 150 && count_y <= 250)
					mlx->img.data[count_y * 800 + count_x] = 0;
				if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
					mlx->img.data[count_y * 800 + count_x] = 0xFF0000;
			}
		}
		mlx->pos.middle = 1;
		mlx->pos.up = 0;
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
	}
}