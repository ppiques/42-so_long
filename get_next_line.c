/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:20:00 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/23 15:39:48 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_save(char *save)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	ret = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!ret)
		return (0);
	i++;
	while (save[i])
		ret[j++] = save[i++];
	ret[j] = '\0';
	free(save);
	return (ret);
}

int	error_check(int fd, char *buff, char **line)
{
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!buff)
		return (-1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				nl;

	nl = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (error_check(fd, buff, line) == -1)
		return (-1);
	while (!newline_end(save) && nl != 0)
	{
		nl = read(fd, buff, BUFFER_SIZE);
		if (nl == -1)
		{
			free(buff);
			return (-1);
		}
		buff[nl] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);
	if (nl == 0)
		return (0);
	return (1);
}
