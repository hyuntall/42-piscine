/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:55:20 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/07 16:40:01 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);
static char	*g_dest;

void	ft_itoa_base(long long nbr, char *base)
{
	unsigned int	base_num;

	base_num = 0;
	while (base[base_num])
		base_num++;
	if (nbr / base_num <= 0)
	{
		*g_dest = base[nbr % base_num];
		g_dest++;
		return ;
	}
	ft_itoa_base(nbr / base_num, base);
	*g_dest = base[nbr % base_num];
	g_dest++;
	return ;
}

int	size_mem(char *base, long long nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	while (nbr / i > 0)
	{
		nbr = nbr / i;
		j++;
	}
	return (j);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		new_nbr;
	char			*temp;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	new_nbr = ft_atoi_base(nbr, base_from);
	if (new_nbr < 0)
	{
		new_nbr = -new_nbr;
		g_dest = malloc(sizeof(char *) * (size_mem(base_to, new_nbr) + 2));
		temp = g_dest;
		*g_dest = '-';
		g_dest++;
	}
	else
	{
		g_dest = malloc(sizeof(char *) * (size_mem(base_to, new_nbr) + 1));
		temp = g_dest;
	}
	if (!g_dest)
		return (0);
	ft_itoa_base(new_nbr, base_to);
	*g_dest = '\0';
	return (temp);
}
