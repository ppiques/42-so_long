/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:06:08 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:54:54 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define F_KEY 102

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

typedef int	t_bool;

typedef struct s_img
{
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	int		sprite_anim;
	int		sprite_anim_ennemy;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	char	keycode;
}				t_img;

typedef struct s_map
{
	char	**map;
	int		line_nbr;
	int		line_len;
	int		column_nbr;
	int		position_nbr;
	int		collectibles_nbr;
	int		ennemy_nbr;
	int		player_ammo;
	int		move_count;
	int		exit_nbr;
}				t_map;

typedef struct s_engine
{
	t_map	*map;
	t_img	*final_img;
	t_img	*sprite;
}				t_engine;

void		move_up(t_engine *engine, int x, int y);
void		move_left(t_engine *engine, int x, int y);
void		move_down(t_engine *engine, int x, int y);
void		move_right(t_engine *engine, int x, int y);
void		player_firing(t_engine *engine, int x, int y);

void		set_map_struct(t_map *map);

void		put_whole_map(t_engine *engine);
void		set_wall_sprite(t_engine *engine, int i, int j);
void		set_background_sprite(t_engine *engine, int i, int j);
void		set_player_sprite(t_engine *engine, int i, int j);
void		set_player_firing_sprite(t_engine *eng, int i, int j);
void		set_exit_sprite(t_engine *engine, int i, int j);
void		set_openexit_sprite(t_engine *engine, int i, int j);
void		find_and_replace_openexit_sprite(t_engine *engine);

int			render_next_frame(t_engine *engine);

void		set_animated_collectibles(t_engine *engine);
void		set_collectible_sprite(t_engine *engine, int i, int j);
void		set_collectible1_sprite(t_engine *engine, int i, int j);
void		set_collectible2_sprite(t_engine *engine, int i, int j);
void		set_collectible3_sprite(t_engine *engine, int i, int j);
void		set_collectible4_sprite(t_engine *engine, int i, int j);

void		ennemy_event(t_engine *engine);
void		set_ennemy_sprite(t_engine *engine, int i, int j);
void		set_alerted_guard_sprite(t_engine *eng, int i, int j);
void		set_patrol_ennemys(t_engine *engine);
void		patrol_move_up(t_engine *engine, int x, int y);
void		patrol_move_down(t_engine *engine, int x, int y);
void		put_move_count_to_image(t_engine *engine);
void		put_ammo_count_to_image(t_engine *engine);
void		free_space_event(t_engine *engine, int x, int y);
void		collectibles_event(t_engine *engine, int x, int y);

void		my_mlx_pixel_put(t_img *img, int x, int y, char *pixel);
void		set_bonus_utils_value(t_engine *engine);
void		quit_event(t_engine *engine);
void		exit_event(t_engine *engine);
void		free_engine(t_engine *engine);
void		free_image(t_engine *engine);
void		error_free(t_engine *engine);
void		error_free_map(t_engine *engine);

int			close_window(t_engine *engine);

t_bool		arg_check(int argc, char *str, t_engine *engine);
t_bool		arg_number_check(int argc, t_engine *engine);
t_bool		map_check(t_map *map, char *file);
t_bool		cross_check(t_map *map);
t_bool		final_check(t_map *map);

t_map		*create_map(int fd, char *file, t_map *map);

t_engine	*malloc_engine(t_engine *engine);

int			get_next_line(int fd, char **line);
int			get_line(char **line, char **stock, int *eof);
int			fill_line(char **line, char *buffer, char **stock);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *str);
t_bool		ft_open_rdonly(int *fd, char *file);

#endif
