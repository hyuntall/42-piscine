/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:50:02 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/25 19:46:12 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(info *info, int nbr)
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

int	ft_lltoa(info *info, long long num)
{
	char	*result;
	int		len;
	int		cnt;

	len = nbr_len(info, num);
	if (info->width > len)
		len = info->width;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0); 
	result[len--] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num)
	{
		result[len--] = "0123456789abcdef"[num % info->base_num] - info->uppercase;
		num /= info->base_num;
	}
	if (info ->sign == -1)
		result[len] = '-';
	while (len > -1)
		result[len--] = ' ';
	cnt = ft_print_str(result);
	free(result);
	return (cnt);
}


int	ft_print_num(info *info, long long num)
{
	int	cnt;
	cnt = 0;
	if (info->address)
		cnt += ft_print_str("0x");
	cnt += ft_lltoa(info, num);

	return (cnt);
}
