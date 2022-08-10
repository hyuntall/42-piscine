/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:39:08 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/01 13:16:03 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**g_board;
int		g_numbers[36];
void	ft_putstr(char *str);
void	init_board(int n);
void	exit_board(int n);
int		set_board(int index, int n);

int	ft_atoi_arr(char *str, int n)
{
	int			i;

	i = 0;
	while (*str)
	{
		if (*str >= '1' && *str <= ('0' + n))
		{
			g_numbers[i] = *str - '0';
			i++;
		}
		else if (*str == ' ')
			;
		else
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		n;

	n = 5;
	if (argc == 2)
	{	
		if (!ft_atoi_arr(argv[1], n))
		{
			ft_putstr("Error\n");
			return (0);
		}
		init_board(n);
		if (!set_board(0, n))
			ft_putstr("Error\n");
		exit_board(n);
	}
	else
		ft_putstr("Error\n");
}
