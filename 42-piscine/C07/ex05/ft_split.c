/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:00:58 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/07 16:46:07 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src, char *charset)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && !is_charset(src[j], charset))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	arr_size(char *str, char *charset)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset))
		{
			cnt++;
			while (!is_charset(str[i], charset) && str[i])
				i++;
		}
		i++;
	}
	return (cnt);
}

int	word_size(char *str, char *charset)
{
	int		i;

	i = 0;
	while (is_charset(*str, charset))
		str++;
	while (*str)
	{
		if (is_charset(*str, charset))
			return (i);
		i++;
		str++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**answer;
	int		i;
	int		j;

	i = 0;
	answer = malloc(sizeof(char **) * (arr_size(str, charset) + 1));
	if (!answer)
		return (0);
	j = 0;
	while (i < arr_size(str, charset))
	{
		while (is_charset(str[j], charset))
			j++;
		answer[i] = malloc(sizeof(char *) * word_size(&str[j], charset) + 1);
		if (!answer[i])
			return (0);
		answer[i] = ft_strcpy(answer[i], &str[j], charset);
		j += word_size(&str[j], charset);
		i++;
	}
	answer[i] = 0;
	return (answer);
}
