/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:48:33 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/06 20:42:08 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	i = 0;
	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
		return (0);
	while (i + min < max)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (i);
}
