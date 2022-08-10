/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:24:25 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/29 17:51:26 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int arr[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + arr[i]);
		i++;
	}
	write(1, ", ", 2);
}

int	start(int n)
{
	int		i;
	int		num;

	i = 1;
	num = 0;
	while (i <= n)
	{
		num = num * 10 + i;
		i++;
	}
	return (num);
}

int	end(int n)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (i < n)
	{
		num = num * 10 + (10 - n + i);
		i++;
	}
	return (num);
}

void	ft_print_combn(int n)
{
	int		arr[n];
	int		i;
	int		cnt;

	i = 0;

	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	cnt = 1;
}

int	main(void)
{
	printf("%d \n", start(4));
	printf("%d \n", end(4));
}
