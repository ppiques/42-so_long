/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:16:17 by ppiques           #+#    #+#             */
/*   Updated: 2021/12/13 15:45:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	void	fill_finalstr(char *finalstr, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		finalstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		finalstr[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*finalstr;
	size_t	finalstr_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		finalstr_len = ft_strlen(s2);
	else if (s2 == NULL)
		finalstr_len = ft_strlen(s1);
	else
		finalstr_len = ft_strlen(s1) + ft_strlen(s2);
	finalstr = (char *)malloc(sizeof(char) * (finalstr_len + 1));
	if (finalstr == NULL)
		return (NULL);
	finalstr[finalstr_len] = '\0';
	fill_finalstr(finalstr, s1, s2);
	return (finalstr);
}
