/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:28:47 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/31 17:31:12 by hyuncpar         ###   ########.fr       */
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
	int		plus;
	int		zero;
	int		hash;
	int		space;
	int		width;
	int		dot;
	int		precision;
}			info;
# define BASE "0123456789abcdef"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# include "./Libft/libft.h"

# include "./Libft/ft_substr.c"
# include "./Libft/ft_strlen.c"
# include "./Libft/ft_isdigit.c"
# include "ft_print_string.c"
# include "ft_print_num.c"
# include "ft_processing_num.c"
# include "ft_parse_option.c"
# include "ft_printf.c"

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define ENABLE 1
# define DISABLE 0
# define SMALL 32

void			init_struct(info *info);
int				ft_printf(const char *format, ...);
int		parse_format(va_list ap, char *format);
int		ft_print_char(info *info, char c);
int		ft_print_str(info *info, char *s);
void	parse_flag(info *info, char **format);
void	parse_width(info *info, char **format, va_list ap);
void	parse_precision(info *info, char **format, va_list ap);
int		parse_type(info *info, va_list ap, char c);
int		ft_print_di(info *info, va_list ap);
int		ft_print_u(info *info, va_list ap);
int		ft_print_xX(info *info, va_list ap, char type);
int		ft_print_p(info *info, va_list ap);
int		ft_print_num(info *info, long long num);

//int	ft_isdigit2(int n);
int	parse_atoi(char **s);
#endif
