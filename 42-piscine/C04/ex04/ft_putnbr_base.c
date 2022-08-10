/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:02:44 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/26 23:24:52 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num2(unsigned int nbr, char *base)
{
	unsigned int	base_num;

	base_num = 0;
	while (base[base_num])
		base_num++;
	if (nbr / base_num <= 0)
	{
		write(1, &base[nbr % base_num], 1);
		return ;
	}
	print_num2(nbr / base_num, base);
	write(1, &base[nbr % base_num], 1);
}

int	length_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_unique1(char *str)
{
	int		i;
	int		j;
	char	*p;
	int		l;

	p = str;
	l = length_str(str);
	i = 0;
	while (i < l - 1)
	{
		j = i + 1;
		while (j < l)
		{
			if (p[i] == p[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_base1(char *base)
{
	int		i;

	i = 0;
	if (!is_unique1(base))
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+' || *base == ' ')
			return (0);
		base++;
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{	
	if (check_base1(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	print_num2((unsigned int) nbr, base);
}
