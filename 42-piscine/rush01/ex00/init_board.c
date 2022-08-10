/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:50:12 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/31 22:00:20 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	**g_board;

void	init_board(int n)
{
	int		i;

	i = 0;
	g_board = (int **)malloc(sizeof(int *) * n);
	while (i < n)
	{
		g_board[i] = (int *)malloc(sizeof(int) * n);
		i++;
	}
}

void	exit_board(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		free(g_board[i]);
		i++;
	}
	free(g_board);
}
