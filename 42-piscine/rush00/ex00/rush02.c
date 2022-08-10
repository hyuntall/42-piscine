/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:26:17 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/21 12:35:23 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(char side, char mid, int a)
{
	int		i;

	i = 1;
	while (i <= a)
	{
		if (i == 1 || i == a)
			ft_putchar(side);
		else
			ft_putchar(mid);
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
			ft_print_line('A', 'B', a);
		else if (i == b)
			ft_print_line('C', 'B', a);
		else
			ft_print_line('B', ' ', a);
		i++;
	}
}
