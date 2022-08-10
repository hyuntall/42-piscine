/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:52:52 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/29 22:52:43 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	**g_board;
extern int	g_numbers[36];
int		check_top(int n, int side, int cnt, int temp);
int		check_bottom(int n, int side, int cnt, int temp);
int		check_left(int n, int side, int cnt, int temp);
int		check_right(int n, int side, int cnt, int temp);

int	is_valid(int n)
{
	if (!check_top(n, 0, 1, 0))
		return (0);
	if (!check_bottom(n, n, 1, 0))
		return (0);
	if (!check_left(n, 2 * n, 1, 0))
		return (0);
	if (!check_right(n, 3 * n, 1, 0))
		return (0);
	return (1);
}

int	check_top(int n, int side, int cnt, int temp)
{
	int		i;

	i = 0;
	while (side < n)
	{
		cnt = 1;
		i = 0;
		temp = g_board[i][side];
		while (i < n)
		{
			if (g_board[i][side] > temp)
			{
				temp = g_board[i][side];
				cnt++;
			}
			i++;
		}
		if (g_numbers[side] != cnt)
			return (0);
		side++;
	}
	return (1);
}

int	check_bottom(int n, int side, int cnt, int temp)
{
	int		i;

	while (side < 2 * n)
	{
		cnt = 1;
		i = n - 1;
		temp = g_board[i][side % n];
		while (i >= 0)
		{
			if (g_board[i][side % n] > temp)
			{
				temp = g_board[i][side % n];
				cnt++;
			}
			i--;
		}
		if (g_numbers[side] != cnt)
			return (0);
		side++;
	}
	return (1);
}

int	check_left(int n, int side, int cnt, int temp)
{
	int		i;

	while (side < 3 * n)
	{
		cnt = 1;
		i = 0;
		temp = g_board[side % n][i];
		while (i < n)
		{
			if (g_board[side % n][i] > temp)
			{
				temp = g_board[side % n][i];
				cnt++;
			}
			i++;
		}
		if (g_numbers[side] != cnt)
			return (0);
		side++;
	}
	return (1);
}

int	check_right(int n, int side, int cnt, int temp)
{
	int		i;

	while (side < 4 * n)
	{
		cnt = 1;
		i = n - 1;
		temp = g_board[side % n][i];
		while (i >= 0)
		{
			if (g_board[side % n][i] > temp)
			{
				temp = g_board[side % n][i];
				cnt++;
			}
			i--;
		}
		if (g_numbers[side] != cnt)
			return (0);
		side++;
	}
	return (1);
}
