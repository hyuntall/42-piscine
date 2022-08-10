/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:33:46 by yena              #+#    #+#             */
/*   Updated: 2022/05/21 12:22:06 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char vertex, char line, int x)
{
	int	width;

	width = 0;
	while (width < x)
	{
		if (width == 0 || width == (x - 1))
			ft_putchar(vertex);
		else
			ft_putchar(line);
		width++;
	}
}

void	rush(int x, int y)
{
	int	height;

	height = 0;
	while (height < y)
	{
		if (height == 0 || height == (y - 1))
			print_line('o', '-', x);
		else
			print_line('|', ' ', x);
		ft_putchar('\n');
		height++;
	}
}
