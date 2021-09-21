/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:30:14 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/21 17:38:07 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_SO_LONG_H
# define FT_SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct		s_image
{
	void	*img;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_image;

typedef struct		s_square_pos
{
	int	middle;
	int	up;
	int	down;
	int right;
	int left;
}					t_square_pos;

typedef struct		s_mlx
{
    void		*mlx_ptr;
    void		*mlx_win;
	t_image			img;
	t_square_pos	pos;
}					t_mlx;

int	close(t_mlx *mlx);
int	key_bindings(int keycode, t_mlx *mlx);

int	square_up(t_mlx *mlx);
int	square_down(t_mlx *mlx);
int	square_right(t_mlx *mlx);
int	square_left(t_mlx *mlx);

t_mlx square_init(t_mlx mlx);

#endif