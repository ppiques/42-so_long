/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_get_next_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:12:39 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/10 13:32:16 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*stock_case(char **line, char **stock, char *buffer)
{
	*line = ft_strjoin(*stock, buffer);
	if (*line == NULL)
		return (NULL);
	free(*stock);
	*stock = NULL;
	return (*line);
}

static char	*line_exist_case(char **line, char *buffer)
{
	char	*temp;

	temp = ft_strdup(*line);
	if (temp == NULL)
		return (NULL);
	free(*line);
	*line = ft_strjoin(temp, buffer);
	if (*line == NULL)
		return (NULL);
	free(temp);
	return (*line);
}

int	fill_line(char **line, char *buffer, char **stock)
{
	if (*stock != NULL)
	{
		*line = stock_case(line, stock, buffer);
		if ((*line) == NULL)
			return (ERROR);
	}
	else if (*line != NULL)
	{
		*line = line_exist_case(line, buffer);
		if ((*line) == NULL)
			return (ERROR);
	}
	else
	{
		*line = ft_strdup(buffer);
		if (*line == NULL)
			return (ERROR);
	}
	return (TRUE);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n > 0)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			len;
	int			end_of_file;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (ERROR);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	len = 1;
	*line = NULL;
	while (ft_strchr(buffer, '\n') == NULL && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (ERROR);
		buffer[len] = '\0';
		if (fill_line(line, buffer, &stock) == ERROR)
			return (ERROR);
	}
	if (get_line(line, &stock, &end_of_file) == ERROR)
		return (ERROR);
	if (end_of_file == TRUE)
		return (FALSE);
	return (TRUE);
}
