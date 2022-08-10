/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:40:07 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/01 21:46:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		sum;

	sum = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		sum = sum * nb;
		nb--;
	}
	return (sum);
}
