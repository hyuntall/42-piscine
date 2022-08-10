/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanekim <hanekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:35:29 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/09 03:21:54 by hanekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "point.h"

int	check_min(int **d, int x, int y)
{
	int	min;

	min = d[x - 1][y - 1];
	if (min > d[x][y - 1])
		min = d[x][y - 1];
	if (min > d[x - 1][y])
		min = d[x - 1][y];
	return (min);
}

void	change_map(char **map, t_map_info *map_info, t_point max)
{
	int		i;
	int		j;

	i = 0;
	while (i < max.side)
	{
		j = 0;
		while (j < max.side)
		{
			map[max.x - i][max.y - j] = map_info->full;
			j++;
		}
		i++;
	}
}

void	set_default(t_point *max, int **i_map, t_map_info *map_info)
{
	int	i;
	int	j;

	max->side = 0;
	i = -1;
	while (++i < map_info->row)
	{
		j = -1;
		while (++j < map_info->col)
		{
			if (i_map[i][j])
			{
				max->x = i;
				max->y = j;
				max->side = 1;
				return ;
			}
		}
	}
}

void	dp_map(int **i_map, t_map_info *map_info, t_point *max)
{
	int		i;
	int		j;

	set_default(max, i_map, map_info);
	i = 0;
	while (++i < map_info->row)
	{
		j = 0;
		while (++j < map_info->col)
		{
			if (i_map[i][j] != 0)
				i_map[i][j] = check_min(i_map, i, j) + 1;
			if (max->side < i_map[i][j])
			{
				max->x = i;
				max->y = j;
				max->side = i_map[i][j];
			}
		}
	}
}
