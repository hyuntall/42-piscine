/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:24:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/29 22:52:23 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	**g_board;
void	ft_putchar(char c);
int		is_valid(int n);
int		is_unique(int x, int y, int num, int n);

void	view_board(int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar('0' + g_board[i][j]);
			if (j < n - 1)
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int	set_board(int index, int n)
{
	int		num;

	if (index == n * n)
	{
		if (is_valid(n))
		{
			view_board(n);
			return (1);
		}
		return (0);
	}
	num = 1;
	while (num <= n && index < n * n)
	{
		if (is_unique(index / n, index % n, num, n))
		{
			g_board[index / n][index % n] = num;
			if (set_board(index + 1, n))
				return (1);
			g_board[index / n][index % n] = 0;
		}
		num++;
	}
	return (0);
}

int	is_unique(int x, int y, int num, int n)
{
	int		i;
	int		j;

	i = 0;
	while (i < n)
	{
		if (g_board[x][i] == num)
			return (0);
		i++;
	}
	j = 0;
	while (j < n)
	{
		if (g_board[j][y] == num)
			return (0);
		j++;
	}
	return (1);
}
