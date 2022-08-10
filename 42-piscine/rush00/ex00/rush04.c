/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:36:02 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/21 13:18:39 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_line(char left, char mid, char right, int a)
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
		if (i == 1)
			ft_print_line('A', 'B', 'C', a);
		else if (i == b)
			ft_print_line('C', 'B', 'A', a);
		else
			ft_print_line('B', ' ', 'B', a);
		i++;
	}
}
