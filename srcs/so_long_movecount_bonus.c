/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_movecount_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:13:52 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 14:12:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_move_count_to_image(t_engine *engine)
{
	char	*move;

	if (engine->map->move_count != 0)
	{
		move = ft_itoa(engine->map->move_count);
		mlx_string_put(engine->final_img->mlx_ptr, engine->final_img->win_ptr,
			10, 16, 0xFFFFFFFF, move);
		free(move);
	}
}

void	put_ammo_count_to_image(t_engine *engine)
{
	char	*ammo;

	if (engine->map->move_count != 0)
	{
		ammo = ft_itoa(engine->map->player_ammo);
		mlx_string_put(engine->final_img->mlx_ptr, engine->final_img->win_ptr,
			10, 32, 0xFCCC05, ammo);
		free(ammo);
	}
}
