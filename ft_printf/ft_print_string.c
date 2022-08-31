/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:54:41 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/31 17:24:11 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(info *info, char c)
{
	int	result;

	result = 0;
	if (!info->minus)
	{
		while (--info->width > 0)
			result += write(1, " ", 1);
	}
	result += write(1, &c, 1);
	while (--info->width > 0)
		result += write(1, " ", 1);
	return (result);
}

int	ft_print_str(info *info, char *s)
{
	int	result;
	int	len;
	int	length;

	result = 0;
	len = ft_strlen(s);
	if (info->dot && info->precision < len && info->precision > -1)
		len = info->precision;
	length = info->width - len + 1;
	if (!info->minus)
	{
		while (--length > 0)
			result += write(1, " ", 1);
	}
	while (len-- > 0)
		result += write(1, s++, 1);
	while (--length > 0)
		result += write(1, " ", 1);
	return (result);
}
