/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:24:48 by yena              #+#    #+#             */
/*   Updated: 2022/05/24 12:05:22 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	ft_atoi(char *ascii)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (*ascii == '-')
	{
		sign = -1;
		ascii++;
	}
	while (*ascii >= '0' && *ascii <= '9')
	{
		number = number * 10 + (*ascii - '0');
		ascii++;
	}	
	return (number * sign);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc == 1)
		rush(5, 5);
	if (argc == 3)
	{
		x = ft_atoi(argv[2]);
		y = ft_atoi(argv[1]);
		if (x <= 0 || y <= 0)
			return (0);
		else
			rush(x, y);
	}
	return (0);
}
