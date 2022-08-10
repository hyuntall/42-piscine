/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 22:15:31 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/30 14:50:54 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_bool(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (0);
	else if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		boolean;

	i = 0;
	boolean = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (boolean)
				str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!boolean)
				str[i] += 32;
		}
		boolean = check_bool(str[i]);
		i++;
	}
	return (str);
}
