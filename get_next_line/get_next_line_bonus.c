/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:47:27 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/09/06 21:36:21 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#define BUFF_SIZE	42

char	*ft_read(int fd, char *buff, char *backup)
{
	char	*temp;
	int		rd;

	while (1)
	{
		rd = read(fd, buff, BUFF_SIZE);
		buff[rd] = '\0';
		if (rd == 0)
			break ;
		if (rd == -1)
			return (0);
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(backup, buff);
		if (!backup)
			return (0);
		free(temp);
		temp = NULL;
		if (in_next_line(buff))
			break ;
	}
	return (backup);
}

char	*backup_next_line(char *line)
{
	int		i;
	char	*result;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (result[0] == '\0')
	{
		free(result);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*backup[OPEN_MAX];

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	line = ft_read(fd, buff, backup[fd]);
	backup[fd] = backup_next_line(line);
	free(buff);
	return (line);
}
