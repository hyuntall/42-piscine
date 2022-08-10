#include <stdio.h>
#include <string.h>
#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int main()
{
	{
		printf("======ex00======\n");
		char str[100] = "abcdefg";
		char str1[100] = "a b c";
		printf("%lu %d\n", strlen(str), ft_strlen(str));
		printf("%lu %d\n", strlen(str1), ft_strlen(str1));
	}
	{
		printf("======ex01======\n");
		char str[100] = "abcdefg";
		char str1[100] = "a b c";
		ft_putstr(str); printf("\n");
		ft_putstr(str1); printf("\n");
	}
	
	{
		printf("======ex02======\n");
		int str = 2147483647;
		int str1 = -2147483648;
		int str2 = 0;
		int str3 = -0;
		ft_putnbr(str); printf("\n");
		ft_putnbr(str1); printf("\n");
		ft_putnbr(str2); printf("\n");
		ft_putnbr(str3); printf("\n");
		ft_putnbr(1231); printf("\n");
		ft_putnbr(1111111111); printf("\n");
	}

	{
		printf("======ex03======\n");
		char str[100] = "2147483647";
		char str1[100] = "-2147483648";
		char str2[100] = "      0";
		char str3[100] = "++-+--0";
		char str4[100] = "    	++-+---+---+--123";
		char str5[100] = "	  ++--+---++-123-1abc11";
		printf("%d\n", ft_atoi(str));
		printf("%d\n", ft_atoi(str1));
		printf("%d\n", ft_atoi(str2));
		printf("%d\n", ft_atoi(str3));
		printf("%d\n", ft_atoi(str4));
		printf("%d\n", ft_atoi(str5));
	}
	
	{
		printf("======ex04======\n");
		char base[20] = "0123456789";
		char base1[20] = "01";
		char base2[20] = "0123456789ABCDEF";
		char base3[20] = "poneyvif";
		char base4[20] = "poneyviff";
		int nbr = -4523816;
		int nbr1 = -2147483648;
		printf("base: %s, nbr: %d => \n", base, nbr);
		ft_putnbr_base(nbr, base); printf("\n");
		printf("base: %s, nbr: %d => \n", base1, nbr);
		ft_putnbr_base(nbr, base1); printf("\n");
		printf("base: %s, nbr: %d => \n", base2, nbr);
		ft_putnbr_base(nbr, base2); printf("\n");
		printf("base: %s, nbr: %d => \n", base3, nbr);
		ft_putnbr_base(nbr, base3); printf("\n");
		printf("base: %s, nbr: %d => \n", base4, nbr);
		ft_putnbr_base(nbr, base4); printf("\n");
		printf("base: %s, nbr: %d => \n", base, nbr1);
		ft_putnbr_base(nbr1, base); printf("\n");
		printf("base: %s, nbr: %d => \n", base1, nbr1);
		ft_putnbr_base(nbr1, base1); printf("\n");
		printf("base: %s, nbr: %d => \n", base2, nbr1);
		ft_putnbr_base(nbr1, base2); printf("\n");
		printf("base: %s, nbr: %d => \n", base3, nbr1);
		ft_putnbr_base(nbr1, base3); printf("\n");
		printf("base: %s, nbr: %d => \n", base4, nbr1);
		ft_putnbr_base(nbr1, base4); printf("\n");
	}
	
	{
		printf("======ex05======\n");
		char base[20] = "0123456789";
		char base1[20] = "01";
		char base2[20] = "0123456789ABCDEF";
		char base3[20] = "poneyvif";
		char base4[20] = "poneyviff";
		printf("base:%s, num:4523816 -> %d\n",base, ft_atoi_base("4523816", base));
		printf("base:%s, num:10001010000011100101000 -> %d\n",base1, ft_atoi_base("10001010000011100101000", base1));
		printf("base:%s, num:450728 -> %d\n",base2, ft_atoi_base("450728", base2));
		printf("base:%s, num:nonpeyvp -> %d\n",base3, ft_atoi_base("nonpeyvp", base3));
		printf("base:%s, num:nonpeyvp -> %d\n",base4, ft_atoi_base("nonpeyvp", base4));
		printf("base:%s, num:-2147483648 -> %d\n",base, ft_atoi_base("-2147483648", base));
		printf("base:%s, num:-1000000000000000000000000000000 %d\n", base1, ft_atoi_base("-10000000000000000000000000000000", base1));
		printf("base:%s, num:-80000000 -> %d\n",base2, ft_atoi_base("-80000000", base2));
		printf("base:%s, num:-npppppppppp -> %d\n",base3, ft_atoi_base("-npppppppppp", base3));
	}

}
