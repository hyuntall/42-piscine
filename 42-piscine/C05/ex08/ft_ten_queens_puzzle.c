/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:33:14 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/02 23:09:53 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		g_cnt;
static int		g_board[10];

int	is_valid(int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (g_board[index] == g_board[i])
			return (0);
		if (index - i == g_board[index] - g_board[i])
			return (0);
		if (index - i == g_board[i] - g_board[index])
			return (0);
		i++;
	}
	return (1);
}

void	ft_putint(int i)
{
	char	c;

	c = '0' + i;
	write(1, &c, 1);
}

void	ft_print_board(void)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_putint(g_board[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	queens(int index)
{
	int		i;

	i = 0;
	if (index == 10)
	{
		ft_print_board();
		g_cnt++;
		return ;
	}
	while (i < 10)
	{
		g_board[index] = i;
		if (is_valid(index))
			queens(index + 1);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		i;
	int		j;

	g_cnt = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			g_board[j] = 0;
			j++;
		}
		g_board[0] = i;
		queens(1);
		i++;
	}
	return (g_cnt);
}
