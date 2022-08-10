/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 00:48:56 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/06 23:27:12 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_get_num(int nb)
{
	char	c;

	if (nb / 10 == 0)
	{
		c = '0' + nb;
		write(1, &c, 1);
		return ;
	}
	ft_get_num(nb / 10);
	c = '0' + nb % 10;
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	ft_get_num(nb);
}

void	ft_show_tab(struct s_stock_str *per)
{
	while ((*per).str)
	{
		ft_putstr(per->str);
		ft_putnbr(per->size);
		write(1, "\n", 1);
		ft_putstr(per->copy);
		per++;
	}
}
