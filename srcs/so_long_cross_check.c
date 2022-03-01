/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_cross_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:33:32 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/09 13:55:09 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	left_column_check(int i, int j, t_map *map)
{
	int	x;
	int	y;

	x = i;
	y = j;
	while (y >= 0)
	{
		if (map->map[x][y] == '1')
			return (SUCCESS);
		y--;
	}
	return (ERROR);
}

t_bool	right_column_check(int i, int j, t_map *map)
{
	int	x;
	int	y;

	x = i;
	y = j;
	while (y < map->line_len)
	{
		if (map->map[x][y] == '1')
		{
			if (left_column_check(i, j, map) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		y++;
	}
	return (ERROR);
}

t_bool	bottom_line_check(int i, int j, t_map *map)
{
	int	x;
	int	y;

	x = i;
	y = j;
	while (x < map->line_nbr)
	{
		if (map->map[x][y] == '1')
		{
			if (right_column_check(i, j, map) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		x++;
	}
	return (ERROR);
}

t_bool	top_line_check(int i, int j, t_map *map)
{
	int	x;
	int	y;

	x = i;
	y = j;
	while (x >= 0)
	{
		if (map->map[x][y] == '1')
		{
			if (bottom_line_check(i, j, map) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		x--;
	}
	return (ERROR);
}

t_bool	cross_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0')
			{
				if (top_line_check(i, j, map) == ERROR)
					return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
