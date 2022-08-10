/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:35:52 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/09 03:28:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "point.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
char	**get_map(int fd, t_map_info *map_info);
int		check_map(char **map, t_map_info *map_info);
void	change_map(char **map, t_map_info *map_info, t_point max);
void	dp_map(int **i_map, t_map_info *map_info, t_point *max);

void	print_map(char **map, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->row)
	{
		write(1, map[i], map_info->col);
		write(1, "\n", 1);
		i++;
	}
}

int	**convert_map(char **map, t_map_info *map_info)
{
	int	**i_map;
	int	i;
	int	j;

	i_map = (int **)malloc(sizeof(int *) * (map_info->row));
	if (!i_map)
		return (0);
	i = 0;
	while (i < map_info->row)
	{
		i_map[i] = (int *)malloc(sizeof(int) * (map_info->col));
		if (!i_map[i])
			return (0);
		j = 0;
		while (j < map_info->col)
		{
			if (map[i][j] == map_info->obstacle)
				i_map[i][j] = 0;
			else if (map[i][j] == map_info->empty)
				i_map[i][j] = 1;
			j++;
		}
		i++;
	}
	return (i_map);
}

void	free_memory(char **map, int **i_map, t_map_info *map_info)
{
	int	i;

	i = 0;
	while (i < map_info->row)
	{
		if (!map[i])
			free(map[i]);
		i++;
	}
	if (!map)
		free(map);
	i = 0;
	while (i < map_info->row)
	{
		if (!i_map[i])
			free(i_map[i]);
		i++;
	}
	if (!i_map)
		free(i_map);
}

void	solve(int fd, char ***map, int ***i_map, t_map_info *map_info)
{
	t_point	max;

	*map = get_map(fd, map_info);
	if (!*map || !check_map(*map, map_info))
	{
		write(1, "map error\n", 10);
		return ;
	}
	*i_map = convert_map(*map, map_info);
	if (!i_map)
	{
		write(1, "map error\n", 10);
		return ;
	}
	dp_map(*i_map, map_info, &max);
	change_map(*map, map_info, max);
	if (max.side > 0)
		print_map(*map, map_info);
	free_memory(*map, *i_map, map_info);
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;
	char		**map;
	int			**i_map;
	int			fd;
	int			i;

	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
		{
			fd = open(argv[i], 0);
			if (fd < 0)
			{
				write(1, "map error\n", 10);
				continue ;
			}
			solve(fd, &map, &i_map, &map_info);
			if (fd != -1)
				close(fd);
		}
	}
	else
		solve(0, &map, &i_map, &map_info);
}
