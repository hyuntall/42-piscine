/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:39:01 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/26 17:58:53 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_length(char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int	ft_strncmp2(char *s1, char *s2, int index)
{
	int		i;

	i = 0;
	while (s1[i + index] && s2[i])
	{
		if (s1[i + index] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] && !s1[i + index])
		return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;

	i = 0;
	if (!*to_find)
		return (str);
	if (str_length(str) < str_length(to_find))
		return (0);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_strncmp2(str, to_find, i))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
