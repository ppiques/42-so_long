/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_player_firing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:53:38 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/10 21:09:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_firing(t_engine *engine, int x, int y)
{
	if (engine->map->player_ammo != 0)
	{
		if (engine->map->map[x][y - 1] == 'M')
		{
			engine->map->map[x][y - 1] = '0';
			set_background_sprite(engine, (y - 1) * 32, x * 32);
		}
		if (engine->map->map[x][y + 1] == 'M')
		{
			engine->map->map[x][y + 1] = '0';
			set_background_sprite(engine, (y + 1) * 32, x * 32);
		}
		set_background_sprite(engine, y * 32, x * 32);
		set_player_firing_sprite(engine, y * 32, x * 32);
		engine->map->player_ammo--;
		engine->map->ennemy_nbr--;
	}
}
