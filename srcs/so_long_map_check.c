/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:03:28 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:02:07 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_map_square(t_map *map)
{
	size_t	line_len;
	int		i;

	line_len = 0;
	i = 0;
	while (map->map[i] != NULL)
	{
		if (i != 0)
		{
			if (ft_strlen(map->map[i]) != line_len)
				return (ERROR);
		}
		line_len = ft_strlen(map->map[i]);
		i++;
	}
	return (SUCCESS);
}

t_bool	is_char(t_map *map, char c)
{
	if (c == 'C' || c == 'P' || c == 'E'
		|| c == '0' || c == 'M')
	{
		if (c == 'P')
			map->position_nbr++;
		else if (c == 'C')
			map->collectibles_nbr++;
		else if (c == 'E')
			map->exit_nbr++;
		else if (c == 'M' && BONUS == 0)
			return (ERROR);
		else if (c == 'M' && BONUS == 1)
			map->ennemy_nbr++;
	}
	else if (c != '1')
		return (ERROR);
	return (SUCCESS);
}

t_bool	check_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (is_char(map, map->map[i][j]) == ERROR)
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

t_bool	map_check(t_map *map, char *file)
{
	int	fd;

	if (ft_open_rdonly(&fd, file) == ERROR)
		return (ERROR);
	map = create_map(fd, file, map);
	if (map == NULL)
		return (ERROR);
	close(fd);
	if (is_map_square(map) == ERROR)
		return (ERROR);
	if (check_char(map) == ERROR)
		return (ERROR);
	if (cross_check(map) == ERROR)
		return (ERROR);
	if (final_check(map) == ERROR)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}
