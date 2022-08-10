Name = libft.a
GCC = gcc -Wall -Wextra -Werror
SRC_DIR = ./srcs/
INCLUDE_DIR = ./includes/
SRCS = $(SRC_DIR)ft_putchar.c $(SRC_DIR)ft_swap.c $...
OBJS = $ (SRCS:.c=.o)

//a

all = $ (NAME)

%.o : %.c
	$ (GCC) -c $< -o $@ -I $(INCLUDE_DIR)

$ (NAME) : $ (OBJS)
	ar -rcus $ (NAME) $ (OBJS)

clean :
	rm -f $ (OBJS)

fclearn :
	rm -f $ (NAME)

re : fclean all
