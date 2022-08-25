/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:28:47 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/25 20:05:14 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
typedef	struct _info{
	int		base_num;
	int		sign;
	int		address;
	int		uppercase;
	int		minus;
	int		zero;
	int		width;
}			info;

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./Libft/libft.h"
# include "ft_print_string.c"
# include "ft_print_num.c"
# include "ft_processing_num.c"
# include "ft_parse_option.c"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define ENABLE 1
# define DISABLE 0
# define SMALL 32

# define BASE "0123456789ABCDEF"


int		ft_print_char(char c);

void	parse_flag(info *info, char **format);
void	parse_width(info *info, char **format, va_list ap);
int		parse_type(info *info, va_list ap, char c);
int		ft_print_di(info *info, va_list ap);
int		ft_print_u(info *info, va_list ap);
int		ft_print_xX(info *info, va_list ap, char type);
int		ft_print_p(info *info, va_list ap);
int		ft_print_num(info *info, long long num);

int	ft_isdigit2(int n);
int	parse_atoi(char **s);
#endif
