/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:26 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/10/13 17:28:36 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			break ;
		i++;
	}
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			break ;
		i++;
	}
	if (i == length - 1)
		return (1);
	return (0);
}