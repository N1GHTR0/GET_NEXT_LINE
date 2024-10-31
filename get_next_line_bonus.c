/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyilmaz <ahyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:17:25 by ahyilmaz          #+#    #+#             */
/*   Updated: 2022/12/01 12:37:09 by ahyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_shaper(char *str, char *reader)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\n')
		i++;
	j = i + 1;
	while (str[j] != '\0')
	{
		reader[k] = str[j];
		k++;
		j++;
	}
	reader[k] = '\0';
	i++;
	str[i] = '\0';
}

int	nlfinder(char *reader, int len)
{
	int	i;

	i = 0;
	while (i < len && reader[i] != '\0')
	{
		if (reader[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*reader[256];
	char			*oneline;
	int				controller;

	oneline = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (reader[fd] == NULL)
		reader[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
	oneline = ft_strjoin(oneline, reader[fd]);
	while (nlfinder(reader[fd], BUFF_SIZE) == 0)
	{
		controller = read(fd, reader[fd], BUFF_SIZE);
		if (controller == -1)
		{
			return (NULL);
			free(reader[fd]);
		}
		reader[fd][BUFF_SIZE] = '\0';
		oneline = ft_strjoin(oneline, reader[fd]);
	}
	ft_shaper(oneline, reader[fd]);
	return (oneline);
}
