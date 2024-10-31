/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahyilmaz <ahyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:47:37 by ahyilmaz          #+#    #+#             */
/*   Updated: 2022/12/03 14:02:45 by ahyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 5
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int	ft_strlen(char *str);
int	ft_strlen_untill_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int	nlfinder(char *str);
char	*get_the_whole_str(int fd, char *after_str);
char	*get_the_line(char *oneline);
char	*get_next_line(int fd);

#endif
