#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>


typedef struct		s_image
{
	void	*img;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_image;

typedef struct		s_mlx
{
    void		*mlx_ptr;
    void		*mlx_win;
	t_image		img;
}					t_mlx;

typedef struct		s_keys
{
	char		up;
	char		down;
	char		left;
	char		right;
	char		escape;
}					t_keys;

int	square_right(int keycode, t_mlx *mlx)
{
	int count_x;
	int count_y;

	count_y = -1;

	printf("Moved square!\n");
	while(++count_y < 600)
	{
		count_x = -1;
		while (++count_x < 800)
		{
			if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
				mlx->img.data[count_y * 800 + count_x] = 0;
			if (count_x >= 450 && count_x <= 550 && count_y >= 250 && count_y <= 350)
				mlx->img.data[count_y * 800 + count_x] = 0x000000FF;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img, 0, 0);
}

int	close(int keycode, t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	return (0);
}

int main(void)
{
	t_mlx mlx;
	int	count_x;
	int	count_y;
	int stop;

	count_y = -1;
	stop = 0;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 800, 600, "Moving square");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr, 800, 600);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, 
											&mlx.img.endian);
	while (++count_y < 600) // 1  pixel sur 2 en blanc
	{
		count_x = -1;
		while (++count_x < 800)
		{
			if (count_x % 2)
				mlx.img.data[count_y * 800 + count_x] = 0xFFFFFF;
			else
				mlx.img.data[count_y * 800 + count_x] = 0;
		}
	}
	count_y = -1;
	while(++count_y < 600 && stop != 1) // carré au milieu
	{
		count_x = -1;
		while (++count_x < 800)
		{
			if (count_x >= 350 && count_x <= 450 && count_y >= 250 && count_y <= 350)
				mlx.img.data[count_y * 800 + count_x] = 0xFF0000;
		}
	}
	stop = 1;



	mlx_hook(mlx.mlx_win, 2, 1L<<0, square_right, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}


// int main(void)
// {
//     data_t        data;

//     if ((data.mlx_ptr = mlx_init()) == NULL)
//         return (EXIT_FAILURE);
//     if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
//         return (EXIT_FAILURE);
// 	if ((data.img = mlx_new_image(data.mlx_ptr, 600, 400)) == NULL)
// 		return (EXIT_FAILURE);
//     mlx_loop(data.mlx_ptr);
//     return (EXIT_SUCCESS);
// }

// void	ft_mlx_pixel_put(image_t *image, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = image->addr + (y * image->line_length + x * (image->bit_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	ft_pixel_square(image_t *image, data_t *data, int x, int y, int color)
// {
// 	char *dst;
// 	int	x1;
// 	int	y1;
// 	int x2;
// 	int y2;

// 	x1 = 50;
// 	y1 = 50;
// 	x2 = 150;
// 	y2 = 150;

// 	dst = image->addr + (y * image->line_length + x * (image->bit_per_pixel / 8));
// 	*(unsigned int*)dst = color;

// 	while (x1 <= 150)
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image->img, x1, y1);
// 		x1++;
// 	}
// 	while (y1 <= 150)
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image->img, x1, y1);
// 		y1++;
// 	}
// 		while (x2 >= 50)
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image->img, x2, y2);
// 		x2--;
// 	}
// 	while (y2 >= 50)
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, image->img, x2, y2);
// 		y2--;
// 	}
// }