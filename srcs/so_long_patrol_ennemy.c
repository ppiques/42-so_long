/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_patrol_ennemy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:40:38 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:32:42 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ennemy_move_on_player(t_engine *engine, int x, int y)
{
	if (engine->map->map[x + 1][y] == 'P')
		ennemy_event(engine);
	else if (engine->map->map[x - 1][y] == 'P')
		ennemy_event(engine);
}

void	call_function_patrol_ennemy(t_engine *engine, int x, int y)
{
	static t_bool	is_wall;

	if (engine->sprite->sprite_anim_ennemy == 3000)
	{
		ennemy_move_on_player(engine, x, y);
		if (engine->map->map[x + 1][y] == '0' && is_wall == 0)
		{
			patrol_move_down(engine, x, y);
			if (engine->map->map[x + 2][y] == '1')
				is_wall = 1;
		}
		else if (engine->map->map[x - 1][y] == '0' && is_wall == 1)
		{
			patrol_move_up(engine, x, y);
			if (engine->map->map[x - 2][y] == '1')
				is_wall = 0;
		}
		else
			is_wall = 1;
		engine->sprite->sprite_anim_ennemy = 0;
	}
	engine->sprite->sprite_anim_ennemy++;
}

void	set_patrol_ennemys(t_engine *engine)
{
	int	i;
	int	j;

	i = 0;
	while (engine->map->map[i] != NULL)
	{
		j = 0;
		while (engine->map->map[i][j] != '\0')
		{
			if (engine->map->map[i][j] == 'M')
				call_function_patrol_ennemy(engine, i, j);
			j++;
		}
		i++;
	}
}
