/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyuncpar <hyuncpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:28:14 by hyuncpar          #+#    #+#             */
/*   Updated: 2022/05/30 14:51:16 by hyuncpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_address(unsigned long long addr, int cnt)
{
	char	*hex;

	hex = "0123456789abcedf";
	if (addr / 16 == 0)
	{
		while (cnt > 0)
		{
			write(1, "0", 1);
			cnt--;
		}
		write(1, &hex[addr % 16], 1);
		return ;
	}
	ft_print_address(addr / 16, cnt - 1);
	write(1, &hex[addr % 16], 1);
}

void	ft_print_hexa(unsigned char *str, int cnt)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (i < 16 && cnt > 0)
	{
		if (cnt > 1)
		{
			write(1, &hex[*(str + i) / 16], 1);
			write(1, &hex[*(str + i) % 16], 1);
		}
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
		cnt--;
	}
}

void	ft_print_hex(unsigned char *str, int cnt)
{
	int		i;

	i = 0;
	ft_print_hexa(str, cnt);
	if (cnt < 16)
	{	
		while (cnt < 16)
		{
			write(1, "  ", 2);
			if (cnt % 2)
				write(1, " ", 1);
			cnt++;
		}
	}
}

void	ft_print_string(unsigned char *str, int cnt)
{
	int		i;

	i = 0;
	while (i < cnt && i < 16)
	{
		if (*(str + i) >= ' ' && *(str + i) <= '~')
			write(1, str + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{	
	unsigned int		i;

	i = 0;
	while (i < size)
	{
		ft_print_address((unsigned long long)addr + i, 16);
		write(1, ": ", 2);
		ft_print_hex((unsigned char *) addr + i, size - i);
		ft_print_string((unsigned char *) addr + i, size - i);
		write(1, "\n", 1);
		i += 16;
	}
}
