/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_next_frame.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:36:21 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:21:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

void	set_map(t_engine *engine)
{
	int	x;
	int	y;

	get_player_pos(engine->map, &x, &y);
	if (!engine->final_img->keycode)
		engine->final_img->keycode = '0';
	if (engine->final_img->keycode == 'w')
		move_up(engine, x, y);
	else if (engine->final_img->keycode == 'a')
		move_left(engine, x, y);
	else if (engine->final_img->keycode == 's')
		move_down(engine, x, y);
	else if (engine->final_img->keycode == 'd')
		move_right(engine, x, y);
	else if (engine->final_img->keycode == 'f')
		player_firing(engine, x, y);
	else if (engine->final_img->keycode == 'e')
		quit_event(engine);
	engine->final_img->keycode = '0';
}

int	render_next_frame(t_engine *engine)
{
	set_map(engine);
	if (BONUS == 1)
	{
		set_animated_collectibles(engine);
		set_patrol_ennemys(engine);
	}
	mlx_put_image_to_window(engine->final_img->mlx_ptr,
		engine->final_img->win_ptr, engine->final_img->img_ptr, 0, 0);
	if (BONUS == 1)
	{
		put_move_count_to_image(engine);
		put_ammo_count_to_image(engine);
	}
	return (SUCCESS);
}
