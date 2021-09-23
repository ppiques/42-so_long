/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:30:14 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/23 15:48:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_SO_LONG_H
# define FT_SO_LONG_H
# define BUFFER_SIZE 4096

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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


int	key_bindings(int keycode, t_mlx *mlx);
int		close_game(t_mlx *mlx);
int		square_up(t_mlx *mlx);
int		square_down(t_mlx *mlx);
int		square_right(t_mlx *mlx);
int		square_left(t_mlx *mlx);

int		get_next_line(int fd, char **line);
int			newline_end(char *str);
int			error_check(int fd, char *buff, char **line);
char		*get_line(char *str);
char		*get_save(char *save);
char		*ft_strjoin(char *s1, char const *s2);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlen(const char *str);

t_mlx square_init(t_mlx mlx);

#endif