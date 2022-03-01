/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:34:20 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/10 18:44:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_engine *engine, int x, int y)
{
	if (engine->map->map[x - 1][y] == 'C')
	{
		collectibles_event(engine, x - 1, y);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
	else if (engine->map->map[x - 1][y] == 'E'
	&& engine->map->collectibles_nbr == 0)
		exit_event(engine);
	else if (engine->map->map[x - 1][y] == 'M')
		ennemy_event(engine);
	else if (engine->map->map[x - 1][y] == '0')
	{
		free_space_event(engine, x - 1, y);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
}

void	move_left(t_engine *engine, int x, int y)
{
	if (engine->map->map[x][y - 1] == 'C')
	{
		collectibles_event(engine, x, y - 1);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
	else if (engine->map->map[x][y - 1] == 'E'
	&& engine->map->collectibles_nbr == 0)
		exit_event(engine);
	else if (engine->map->map[x][y - 1] == 'M')
		ennemy_event(engine);
	else if (engine->map->map[x][y - 1] == '0')
	{
		free_space_event(engine, x, y - 1);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
}

void	move_down(t_engine *engine, int x, int y)
{
	if (engine->map->map[x + 1][y] == 'C')
	{
		collectibles_event(engine, x + 1, y);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
	else if (engine->map->map[x + 1][y] == 'E'
	&& engine->map->collectibles_nbr == 0)
		exit_event(engine);
	else if (engine->map->map[x + 1][y] == 'M')
		ennemy_event(engine);
	else if (engine->map->map[x + 1][y] == '0')
	{
		free_space_event(engine, x + 1, y);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
}

void	move_right(t_engine *engine, int x, int y)
{
	if (engine->map->map[x][y + 1] == 'C')
	{
		collectibles_event(engine, x, y + 1);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
	else if (engine->map->map[x][y + 1] == 'E'
	&& engine->map->collectibles_nbr == 0)
		exit_event(engine);
	else if (engine->map->map[x][y + 1] == 'M')
		ennemy_event(engine);
	else if (engine->map->map[x][y + 1] == '0')
	{
		free_space_event(engine, x, y + 1);
		engine->map->map[x][y] = '0';
		set_background_sprite(engine, y * 32, x * 32);
	}
}
