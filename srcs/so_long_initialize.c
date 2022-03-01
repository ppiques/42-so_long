/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:48:18 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:26:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_engine	*malloc_engine(t_engine *engine)
{
	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	engine->final_img = (t_img *)malloc(sizeof(t_img));
	if (engine->final_img == NULL)
		return (NULL);
	engine->final_img->keycode = 0;
	engine->sprite = (t_img *)malloc(sizeof(t_img));
	if (engine->sprite == NULL)
		return (NULL);
	engine->map = (t_map *)malloc(sizeof(t_map));
	if (engine->map == NULL)
		return (NULL);
	return (engine);
}

void	set_map_struct(t_map *map)
{
	map->map = NULL;
	map->move_count = 0;
	map->position_nbr = 0;
	map->line_len = 0;
	map->line_nbr = 0;
	map->column_nbr = 0;
	map->collectibles_nbr = 0;
	map->player_ammo = 0;
	map->ennemy_nbr = 0;
	map->exit_nbr = 0;
}

void	check_tile(t_engine *engine, char c, int y_pos, int x_pos)
{
	if (c == 'P' || c == 'M' || c == 'E' || c == '0')
		set_background_sprite(engine, y_pos, x_pos);
	if (c == '1')
		set_wall_sprite(engine, y_pos, x_pos);
	else if (c == 'C')
		set_collectible_sprite(engine, y_pos, x_pos);
	else if (c == 'P')
		set_player_sprite(engine, y_pos, x_pos);
	else if (c == 'E' && engine->map->collectibles_nbr != 0)
		set_exit_sprite(engine, y_pos, x_pos);
	else if (c == 'E' && engine->map->collectibles_nbr == 0)
		set_openexit_sprite(engine, y_pos, x_pos);
	else if (c == 'M' && BONUS == 1)
		set_ennemy_sprite(engine, y_pos, x_pos);
}

void	put_whole_map(t_engine *engine)
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
			check_tile(engine, engine->map->map[i][j], y_pos, x_pos);
			y_pos = y_pos + 32;
			j++;
		}
		x_pos = x_pos + 32;
		i++;
	}
}
