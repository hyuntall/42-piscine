GCC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = includes
NAME = libft.a
SRCS = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar cr $@ $^

.c.o :
	$(GCC) $(CFLAG) -c $< -o $@ -I $(INCLUDE)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
