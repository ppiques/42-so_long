/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:52:38 by ppiques           #+#    #+#             */
/*   Updated: 2021/09/23 15:40:00 by ppiques          ###   ########.fr       */
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

char	*get_line(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*sc;
	char	*dst;

	if (dest == src)
		return (dest);
	sc = (char *)src;
	dst = (char *)dest;
	if (dst > sc)
	{
		i = n;
		while (i-- > 0)
			dst[i] = sc[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = sc[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	str_len;
	char	*ret;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	str_len = s1_len + s2_len + 1;
	ret = malloc(sizeof(char) * str_len);
	if (!ret)
		return (0);
	ft_memmove(ret, s1, s1_len);
	ft_memmove(ret + s1_len, s2, s2_len);
	ret[str_len - 1] = '\0';
	free(s1);
	return (ret);
}

int	newline_end(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
