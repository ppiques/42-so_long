/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_animated_collectibles_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:22:02 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:32:09 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call_animated_collectibles_funct(t_engine *engine, int y_pos, int x_pos)
{
	if (engine->sprite->sprite_anim == 250)
		set_collectible1_sprite(engine, y_pos, x_pos);
	else if (engine->sprite->sprite_anim == 500)
		set_collectible2_sprite(engine, y_pos, x_pos);
	else if (engine->sprite->sprite_anim == 1000)
		set_collectible3_sprite(engine, y_pos, x_pos);
	else if (engine->sprite->sprite_anim == 1500)
	{
		set_collectible4_sprite(engine, y_pos, x_pos);
		engine->sprite->sprite_anim = 0;
	}
}

void	set_animated_collectibles(t_engine *engine)
{
	int	i;
	int	j;
	int	x_pos;
	int	y_pos;

	engine->sprite->sprite_anim++;
	i = 0;
	x_pos = 0;
	while (engine->map->map[i] != NULL)
	{
		j = 0;
		y_pos = 0;
		while (engine->map->map[i][j] != '\0')
		{
			if (engine->map->map[i][j] == 'C')
				call_animated_collectibles_funct(engine, y_pos, x_pos);
			y_pos = y_pos + 32;
			j++;
		}
		x_pos = x_pos + 32;
		i++;
	}
}
