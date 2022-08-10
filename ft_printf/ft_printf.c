/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:04:56 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/10 19:20:57 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	check_type(va_list ap, char *c)
{
	int		cnt;

	cnt = 0;
	if (*c == 'c')
		cnt += ft_putchar(va_arg(ap, int));
	if (*c == 's')
		cnt += ft_putstr(va_arg(ap, char *));
	if (*c == '%')
		cnt += ft_putchar('%');
	return (cnt);
}

int	parse_format(va_list ap, char *format)
{
	int	result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			// if (ft_strchr("#0 '+-"))
			// if (ft_strchr("n*"))
			if (ft_strchr("cspdiuxX%", *format))
				result += check_type(ap, format);
		}
		else
		{
			ft_putchar(*format);
			result++;
		}
		format++;
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	result = parse_format(ap, (char *)format);
	va_end(ap);
	return (result);
}

int	main()
{
	char *asd;

	asd = "sad";
	printf("\n%d", ft_printf("aaa%c %s %% %pad", 'i', "Sada", asd));
	printf("\n%p", asd);
}
