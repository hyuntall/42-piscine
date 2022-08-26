/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:59:56 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/26 18:13:51 by hyuncpar         ###   ########.fr       */
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

void	parse_flag(info *info, char **c)
{
	while (**c == '-' || **c == '0' || **c == '*' || **c == '+' || **c == ' ')
	{
		if (**c == '0')
			info->zero = 1;
		else if (**c == '+')
			info->plus = 1;
		else if (**c == '#')
			info->hash = 1;
		else if (**c == ' ')
			info->space = 1;
		else
			info->minus = 1;
		(*c)++;
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
		{
			info->width *= -1;
			info->minus = 1;
			if (info->zero == 1)
				info->zero = 0;
		}
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
