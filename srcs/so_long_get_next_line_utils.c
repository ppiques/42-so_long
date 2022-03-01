/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_next_line_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:14:44 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/09 15:16:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (s[i])
	{
		if (c == s[i])
			return (&str[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (&str[i]);
	return (NULL);
}

static void	fill_line_and_stock(char *line, char *stock, char *temp)
{
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	i++;
	j = 0;
	while (temp[i] != '\0')
	{
		stock[j] = temp[i];
		i++;
		j++;
	}
	stock[j] = '\0';
}

static char	*malloc_line_and_stock(char **line, char **stock, char *temp)
{
	int		i;
	int		j;

	temp = ft_strdup(*line);
	free(*line);
	i = 0;
	while (temp[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if ((*line) == NULL)
		return (NULL);
	j = 0;
	while (temp[++i] != '\0')
		j++;
	*stock = (char *)malloc(sizeof(char) * (j + 1));
	if ((*stock) == NULL)
		return (NULL);
	return (temp);
}

int	get_line(char **line, char **stock, int *eof)
{
	char	*temp;

	temp = NULL;
	if (ft_strchr(*line, '\n') != NULL)
	{
		*eof = 0;
		temp = malloc_line_and_stock(line, stock, temp);
		if (temp == NULL)
			return (ERROR);
		fill_line_and_stock(*line, *stock, temp);
		free(temp);
	}
	else if (ft_strchr(*line, '\0') != NULL)
		*eof = TRUE;
	return (TRUE);
}
