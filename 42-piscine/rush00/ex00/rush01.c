/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyu <seungyu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:55:51 by seungyu           #+#    #+#             */
/*   Updated: 2022/05/21 13:07:03 by seungyu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(char first, char second, char last, int a)
{
	int		i;

	i = 1;
	while (i <= a)
	{
		if (i == 1)
			ft_putchar(first);
		else if (i == a)
			ft_putchar(last);
		else
			ft_putchar(second);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int a, int b)
{
	int		i;

	i = 1;
	while (i <= b)
	{
		if (i == 1)
			ft_print_line('/', '*', '\\', a);
		else if (i == b)
			ft_print_line('\\', '*', '/', a);
		else
			ft_print_line('*', ' ', '*', a);
		i++;
	}
}
