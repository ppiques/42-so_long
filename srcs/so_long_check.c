/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:33:41 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:56:41 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (ERROR);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		return (ERROR);
	}
	return (SUCCESS);
}

t_bool	check_arg_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[--i] != 'r')
		return (ERROR);
	if (str[--i] != 'e')
		return (ERROR);
	if (str[--i] != 'b')
		return (ERROR);
	if (str[--i] != '.')
		return (ERROR);
	if (i == 0 || str[i - 1] == '/')
		return (ERROR);
	else
		return (SUCCESS);
}

t_bool	arg_number_check(int argc, t_engine *engine)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		error_free(engine);
		return (ERROR);
	}
	return (SUCCESS);
}

t_bool	arg_check(int argc, char *str, t_engine *engine)
{
	if (arg_number_check(argc, engine) == ERROR)
		return (ERROR);
	if (check_arg_format(str) == ERROR)
	{
		printf("Error\nFile is not in .ber format\n");
		error_free(engine);
		return (ERROR);
	}
	if (check_file(str) == ERROR)
	{
		printf("Error\nFile is not valid");
		error_free(engine);
		return (ERROR);
	}
	set_map_struct(engine->map);
	if (map_check(engine->map, str) == ERROR)
	{
		printf("Error\nMap is not valid");
		error_free_map(engine);
		return (ERROR);
	}
	return (SUCCESS);
}

t_bool	final_check(t_map *map)
{
	if (map->exit_nbr >= 1 && map->position_nbr == 1
		&& map->collectibles_nbr >= 1 && map->line_len >= 3
		&& map->line_nbr >= 3)
		return (SUCCESS);
	return (ERROR);
}
