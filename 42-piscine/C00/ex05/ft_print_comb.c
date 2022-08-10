/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:29:23 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/21 18:31:20 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_num(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
	if (a == '7' && b == '8' && c == '9')
		return ;
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '9')
	{
		b = a + 1;
		c = b + 1;
		while (b <= '9' && b >= a)
		{
			while (c <= '9' && c >= b)
			{
				ft_print_num(a, b, c);
				c++;
			}
			b++;
			c = b + 1;
		}
		a++;
	}
}
