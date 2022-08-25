/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:50:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/25 20:06:29 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(info *info)
{
	info->address = 0;
	info->base_num = 10;
	info->sign = 0;
	info->uppercase = 0;
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
}

int	parse_format(va_list ap, char *format)
{
	info	info;
	int		result;

	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			init_struct(&info);
			parse_flag(&info, &format);
			parse_width(&info, &format, ap);
			result += parse_type(&info, ap, *format);
		}
		else
			result += ft_print_char(*format);
		format++;
	}
	write(1, &"\n", 1);
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
	char *test = "sada";
	printf("\n\n\n%d\n", ft_printf("dsa%---s %---c %5d %p", "asdas", 'G', 99, test));
	printf("%-4.c", 'y');
}