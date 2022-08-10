/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:08:25 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/07 12:20:19 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	arr_len(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			sum++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			sum++;
			j++;
		}
		i++;
	}
	return (sum);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*answer;
	int		i;

	i = 0;
	if (size == 0)
		answer = (char *)malloc(sizeof(char));
	else
		answer = (char *)malloc(sizeof(char) * (arr_len(size, strs, sep) + 1));
	if (!answer)
		return (0);
	answer[0] = '\0';
	while (i < size)
	{
		answer = ft_strcat(answer, strs[i]);
		if (i < size - 1)
			answer = ft_strcat(answer, sep);
		i++;
	}
	return (answer);
}
