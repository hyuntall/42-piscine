/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:35:00 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/26 17:59:03 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_di(info *info, va_list ap)
{
	int			cnt;
	long long	num;
	info->base_num = 10;
	num = va_arg(ap, int);
	if (num < 0)
	{
		info->sign = 0;
		num *= -1;
		//(info->width)--;
		
	}
	
	cnt = ft_print_num(info, num);
	return (cnt);
}

int	ft_print_u(info *info, va_list ap)
{
	int			cnt;
	long long	num;

	info->base_num = 10;
	num = va_arg(ap, unsigned int);
	cnt = ft_print_num(info, num);
	return (cnt);
}

int	ft_print_xX(info *info, va_list ap, char type)
{
	int			cnt;
	long long	num;

	info->base_num = 16;
	if (type == 'X')
		info->uppercase = -32;
	num = va_arg(ap, unsigned int);
	cnt = ft_print_num(info, num);
	return (cnt);
}

int	ft_print_p(info *info, va_list ap)
{
	int			cnt;
	long long	num;

	info->base_num = 16;
	info->address = 1;
	num = (unsigned long)va_arg(ap, void *);
	cnt = ft_print_num(info, num);
	return (cnt);
}