/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:50:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/06 17:11:18 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tmp;
	int			i;

	i = 0;
	tmp = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!tmp)
		return (0);
	while (i < ac)
	{
		tmp[i].size = ft_strlen(av[i]);
		tmp[i].str = av[i];
		tmp[i].copy = ft_strdup(av[i]);
		i++;
	}
	tmp[i].str = 0;
	return (tmp);
}
