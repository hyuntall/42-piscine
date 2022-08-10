/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:55:42 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/10 19:17:47 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	nbr_len(int nbr, int type)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr != 0)
	{
		nbr /= type;
		len++;
	}
	return (len);
}
