/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:59:17 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/14 14:20:39 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	free_space_event(t_engine *engine, int x, int y)
{
	engine->map->move_count++;
	if (BONUS == 0)
		printf("NUMBER OF MOVES : %d\n", engine->map->move_count);
	engine->map->map[x][y] = 'P';
	set_player_sprite(engine, y * 32, x * 32);
}

void	collectibles_event(t_engine *engine, int x, int y)
{
	engine->map->move_count++;
	if (BONUS == 0)
		printf("NUMBER OF MOVES : %d\n", engine->map->move_count);
	engine->map->collectibles_nbr--;
	engine->map->player_ammo++;
	engine->map->map[x][y] = 'P';
	set_player_sprite(engine, y * 32, x * 32);
	if (engine->map->collectibles_nbr == 0)
		find_and_replace_openexit_sprite(engine);
}

void	ennemy_event(t_engine *engine)
{
	engine->map->move_count++;
	free_engine(engine);
	printf("GAME OVER\n");
	exit(EXIT_SUCCESS);
}

void	exit_event(t_engine *engine)
{
	engine->map->move_count++;
	printf("Congratulations! You won the game in %d moves!\n",
		engine->map->move_count);
	free_engine(engine);
	exit(EXIT_SUCCESS);
}

void	quit_event(t_engine *engine)
{
	free_engine(engine);
	printf("User closed the game.\n");
	exit(EXIT_SUCCESS);
}
