/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:59:56 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/25 19:45:00 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit2(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	parse_atoi(char **s)
{
	int	result;

	result = 0;
	while (ft_isdigit2(**s))
	{
		result = result * 10 + **s - '0';
		(*s)++;
	}
	return (result);
}

void	parse_flag(info *info, char **format)
{
	
	while (**format == '-' || **format == '0' || **format == '*')
	{
		if (**format == '0')
			info->zero = 1;
		else
			info->minus = 1;
		(*format)++;
	}
}

void	parse_width(info *info, char **format, va_list ap)
{
	if (ft_isdigit2(**format))
		info->width = parse_atoi(format);
	else if (**format == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		;
		(*format)++;
	}
}

int	parse_type(info *info, va_list ap, char c)
{
	int	cnt;
	cnt = 0;
	if (c == 'c')
		cnt += ft_print_char(va_arg(ap, int));
	if (c == 's')
		cnt += ft_print_str(va_arg(ap, char *));
	if (c == 'p')
		cnt += ft_print_p(info, ap);
	if (c == 'd' || c == 'i')
		cnt += ft_print_di(info, ap);
	if (c == 'x' || c == 'X')
		cnt += ft_print_xX(info, ap, c);
	return (cnt);
}