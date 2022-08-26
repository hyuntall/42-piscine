/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:50:02 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/26 18:20:04 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(info *info, long long nbr)
{
	int	len;	

	len = 0;
	if (nbr == 0)
		return (1);
	else if (info->sign == -1)
		len++;
	while (nbr != 0)
	{
		nbr /= info->base_num;
		len++;
	}
	return (len);
}

void	left_sort_str(info *info, char **result, long long num, int len)
{
	int	i;

	i = 0;
	if (!info->sign || info->plus)
	{
		if (!info->sign)
			(*result)[i++] = '-';
		if (info->sign && info->plus)
			(*result)[i++] = '+';
		len += 2;
	}
	if (info->address)
	{
		(*result)[i++] = '0';
		(*result)[i++] = 'x';
		len += 4;
	}
	while (num)
	{
		(*result)[len - i++ - 1] = BASE[num % info->base_num] - info->uppercase;
		num /= info-> base_num;
	}
	while (i < info->width + 1)
		(*result)[i++] = ' ';
}

void	right_sort_str(info *info, char **result, long long num)
{
	printf("!!%d", info->width);
	while (num)
	{
		(*result)[info->width--] = BASE[num % info->base_num] - info->uppercase;
			num /= info->base_num;
	}
	printf("!!%d", info->width);
	if (!info ->sign)
		(*result)[info->width--] = '-';
	if (info->sign && info->plus)
		(*result)[info->width--] = '+';
	if (info->address)
	{
		(*result)[info->width--] = 'x';
		(*result)[info->width--] = '0';
	}
	while (info->width > -1)
		(*result)[info->width--] = ' ';
}

int	ft_lltoa(info *info, long long num)
{
	char	*result;
	int		len;
	int		cnt;
	int		i;

	len = nbr_len(info, num);
	i = 0;
	if (info->width < len)
	{
		info->width = len;
		if (!info->sign || info->plus)
			info->width++;
	}
	result = (char *)malloc(sizeof(char) * (info->width + 1));
	if (!result)
		return (0);
	result[info->width--] = '\0';
	while (i < info->width)
		result[i++] = ' ';
	if (num == 0)
		result[0] = '0';
	if (info->minus)
		left_sort_str(info, &result, num, len);
	else
		right_sort_str(info, &result, num);
	cnt = ft_print_str(result);
	free(result);
	return (cnt);
}


int	ft_print_num(info *info, long long num)
{
	int	cnt;
	int	len;

	cnt = 0;
	len = nbr_len(info, num);
	cnt += ft_lltoa(info, num);

	return (cnt);
}
