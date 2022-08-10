/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:42:58 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/06 20:39:01 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		i;
	int		*arr;

	if (min >= max)
		return (0);
	i = 0;
	arr = malloc(sizeof(int) * (max - min));
	if (!arr)
		return (0);
	while (i + min < max)
	{
		arr[i] = i + min;
		i++;
	}
	return (arr);
}
