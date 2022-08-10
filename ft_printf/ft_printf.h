/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:04:19 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/08/10 19:20:55 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./Libft/libft.h"

# include "print_utils.c"
# include "./Libft/ft_strlen.c"
# include "./Libft/ft_strchr.c"

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(int n);
#endif