/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:05:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/21 12:32:29 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(char left, char right, char mid, int a)
{
	int		i;

	i = 1;
	while (i <= a)
	{
		if (i == 1)
			ft_putchar(left);
		else if (i == a)
			ft_putchar(right);
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
		if (i == 1 || i == b)
			ft_print_line('A', 'C', 'B', a);
		else
			ft_print_line('B', 'B', ' ', a);
		i++;
	}
}
