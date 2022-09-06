/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:47:54 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/06 21:36:24 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

char	*get_next_line(int fd);
char	*backup_next_line(char *line);
char	*ft_read(int fd, char *buff, char *backup);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		in_next_line(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif