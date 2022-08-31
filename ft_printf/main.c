#include "ft_printf.h"

int	main()
{
    char c = 'y';
	char *s = "abc";
	ft_printf("1-->|%-4.c|<--\n", c);
	ft_printf("2-->|%-4c|<--\n", c);
	ft_printf("3-->|%-3.c|<--\n", c);
	ft_printf("4-->|%-3.c|<--\n", c);
	ft_printf("5-->|%-2.c|<--\n", c);
    ft_printf("---------------------\n");
    ft_printf("1-->|%-16.0s|<--\n", s);
	ft_printf("2-->|%-16.*s|<--\n", 0, s);
	ft_printf("3-->|%-16.*s|<--\n", -3, s);
	ft_printf("4-->|%-16.*s|<--\n", -2, s);
	ft_printf("5-->|%-16.15s|<--\n", s);
    printf("6-->|%-16.*s|<--\n", 0, s);
}