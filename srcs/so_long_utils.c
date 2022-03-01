/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:02:43 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 16:00:39 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, char *pixel)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dst = *(int *)pixel;
}

t_bool	ft_open_rdonly(int *fd, char *file)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
	{
		close(*fd);
		return (ERROR);
	}
	return (SUCCESS);
}

static int	nbrlen(long n)
{
	if (n < 0)
		return (1 + nbrlen(-n));
	else if (n / 10 > 0)
		return (1 + nbrlen(n / 10));
	else
		return (1);
}

char	*ft_itoa_operation(int len, int nbr, char *str)
{
	int	minus;

	minus = 0;
	if (*str == '-')
		minus = 1;
	while (len > minus)
	{
		if (nbr >= 10)
		{
			*(str + --len) = nbr % 10 + '0';
			nbr = nbr / 10;
		}
		else
			*(str + --len) = '0' + nbr;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = nbrlen(nbr);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		*str = '-';
		nbr = nbr * -1;
	}
	else
		*str = '0';
	*(str + len) = '\0';
	str = ft_itoa_operation(len, nbr, str);
	return (str);
}
