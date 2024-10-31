/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyilmaz <ahyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:54 by ahyilmaz          #+#    #+#             */
/*   Updated: 2022/12/03 14:32:31 by ahyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	if (str == NULL)
		return (0);
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	ft_strlen_untill_newline(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (str[x] == '\n')
		return (x + 1);
	if (str[x] == '\0')
		return (x);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}

int	nlfinder(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
