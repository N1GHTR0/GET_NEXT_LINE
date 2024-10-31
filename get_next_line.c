/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyilmaz <ahyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:17:08 by ahyilmaz          #+#    #+#             */
/*   Updated: 2022/12/03 16:24:42 by ahyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "get_next_line.h"

char	*get_after_newline(char *oneline)
{
	int 	i;
	int		j;
	char	*after_str;

	after_str = NULL;
	i = 0;
	j = 0;
	while (oneline[i] != '\n' && oneline[i] != '\0')
		i++;
	if (oneline[i] == '\0')
		return (NULL);
	after_str = malloc(sizeof(char) * ft_strlen(oneline + (i + 1)) + 1);
	i++;
	while (oneline[i] != '\0')
	{
		after_str[j] = oneline[i];
		j++;
		i++;
	}
	after_str[j] = '\0';
	return (after_str);
}

char	*get_the_line(char *oneline)
{
	char *line;
	int i;

	i = 0;
	if (ft_strlen_untill_newline(oneline) <= 0)
		return (NULL);
	line = malloc(((ft_strlen_untill_newline(oneline)) * sizeof(char)) + 1 );
	while (oneline[i] != '\0' && oneline[i] != '\n')
	{
		line[i] = oneline[i];
		i++;
	}
	if (oneline[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	free(oneline);
	return (line);
}

char	*get_the_whole_str(int fd, char *after_str)
{
	char	*buff;
	char	*all_line;
	int		controller;

	all_line = NULL;
	controller = 1;
	if (after_str != NULL)
		all_line = ft_strjoin(all_line, after_str);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buff[0] = '\0';
	while (nlfinder(buff) != 1 && controller != 0)
	{
		controller = read(fd, buff, BUFFER_SIZE);
		if (controller == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[controller] = '\0';
		all_line = ft_strjoin(all_line, buff);
	}
	free(buff);
	return (all_line);
}

char	*get_next_line(int fd)
{
	static char *after_str;
	char	*oneline;
	char	*for_free_after_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	oneline = NULL;
	oneline = get_the_whole_str(fd, after_str);
	for_free_after_str = after_str;
	after_str = get_after_newline(oneline);
	free(for_free_after_str);
	oneline = get_the_line(oneline);
	return (oneline);
}
