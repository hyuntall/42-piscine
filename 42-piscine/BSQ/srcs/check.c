/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanekim <hanekim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:40:21 by hanekim           #+#    #+#             */
/*   Updated: 2022/06/09 03:09:58 by hanekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	check_map_info(t_map_info *map_info)
{
	if (map_info->row < 1)
		return (0);
	if (map_info->empty < ' ' || map_info->empty > '~')
		return (0);
	if (map_info->obstacle < ' ' || map_info->obstacle > '~')
		return (0);
	if (map_info->full < ' ' || map_info->full > '~')
		return (0);
	if (map_info->empty == map_info->obstacle
		|| map_info->obstacle == map_info->full
		|| map_info->full == map_info->empty)
		return (0);
	return (1);
}

int	check_map(char **map, t_map_info *map_info)
{
	int	i;
	int	j;

	if (!check_map_info(map_info))
		return (0);
	i = 0;
	while (i < map_info->row)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != map_info->empty
				&& map[i][j] != map_info->obstacle)
				return (0);
			j++;
		}
		if (j != map_info->col)
			return (0);
		i++;
	}
	return (1);
}
