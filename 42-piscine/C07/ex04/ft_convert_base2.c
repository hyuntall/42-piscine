/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:50:06 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/06/03 21:02:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space2(char c);

int	is_unique(char *str)
{
	int		i;
	int		j;
	char	*p;
	int		len;

	p = str;
	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (p[i] == p[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_base(char *base)
{	
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || is_space2(base[i]))
			return (0);
		i++;
	}
	if (!is_unique(base))
		return (0);
	if (i <= 1)
		return (0);
	return (1);
}

int	hex_to_int(char c, char *base)
{
	int		num;

	num = 0;
	while (base[num])
	{
		if (c == base[num])
			return (num);
		num++;
	}
	return (-1);
}

int	is_space2(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		num;
	int		base_len;

	num = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (!check_base(base))
		return (0);
	sign = 1;
	while (is_space2(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = 0 - sign;
		str++;
	}
	while (*str && hex_to_int(*str, base) != -1)
	{
		num = num * (base_len) + hex_to_int(*str, base);
		str++;
	}
	return (num * sign);
}
