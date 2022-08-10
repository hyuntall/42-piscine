/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanekim <hanekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 03:03:14 by hanekim           #+#    #+#             */
/*   Updated: 2022/06/09 03:09:59 by hanekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

#include <stdlib.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_append(char *dest, char c);
int		ft_atoi(char *str);
int		ft_strlen(char *str);

char	*read_line(int fd)
{
	char	*src;
	char	*tmp;
	char	buff;
	int		len;

	src = (char *)malloc(sizeof(char));
	if (!src)
		return (0);
	*src = '\0';
	len = 0;
	while (read(fd, &buff, 1) > 0 && buff != '\n')
	{
		tmp = src;
		src = (char *)malloc(sizeof(char) * (++len + 1));
		if (!src)
			return (0);
		ft_strcpy(src, tmp);
		ft_append(src, buff);
		free(tmp);
	}
	src[len] = '\0';
	return (src);
}

int	get_map_info(t_map_info *map_info, char *info)
{
	int		i;
	char	*lines;

	if (!info)
		return (0);
	i = 0;
	while (info[i])
		i++;
	lines = (char *)malloc(sizeof(char) * (i - 3 + 1));
	if (!lines)
		return (0);
	i = -1;
	while (info[++i + 3])
		lines[i] = info[i];
	lines[i] = '\0';
	map_info->row = ft_atoi(lines);
	free(lines);
	if (map_info->row < 1)
		return (0);
	map_info->empty = info[i++];
	map_info->obstacle = info[i++];
	map_info->full = info[i];
	free(info);
	return (1);
}

char	**get_map(int fd, t_map_info *map_info)
{
	char	**map;
	char	*tmp;
	int		i;

	if (!get_map_info(map_info, read_line(fd)))
		return (0);
	map = (char **)malloc(sizeof(char *) * (map_info->row));
	if (!map)
		return (0);
	i = -1;
	while (++i < map_info->row)
	{
		tmp = read_line(fd);
		if (!tmp || *tmp == '\0')
			return (0);
		map_info->col = ft_strlen(tmp);
		map[i] = ft_strdup(tmp);
		free(tmp);
	}
	if (read(fd, tmp, 1) > 0)
		return (0);
	return (map);
}
