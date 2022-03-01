/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:52:38 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:44:09 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_engine(t_engine *engine)
{
	int	i;

	i = 0;
	while (engine->map->map[i] != NULL)
	{
		free(engine->map->map[i]);
		i++;
	}
	free(engine->map->map);
	free(engine->map);
	mlx_destroy_image(engine->final_img->mlx_ptr, engine->final_img->img_ptr);
	free (engine->sprite);
	mlx_destroy_window(engine->final_img->mlx_ptr, engine->final_img->win_ptr);
	mlx_destroy_display(engine->final_img->mlx_ptr);
	free (engine->final_img->mlx_ptr);
	free (engine->final_img);
	free (engine);
}

void	error_free(t_engine *engine)
{
	free(engine->final_img);
	free(engine->sprite);
	free(engine->map);
	free(engine);
}

void	error_free_map(t_engine *engine)
{
	int	i;

	i = 0;
	free(engine->final_img);
	free(engine->sprite);
	while (engine->map->map[i] != NULL)
	{
		free(engine->map->map[i]);
		i++;
	}
	free(engine->map->map);
	free(engine->map);
	free(engine);
}

void	free_image(t_engine *engine)
{
	mlx_destroy_image(engine->final_img->mlx_ptr, engine->sprite->img_ptr);
}
