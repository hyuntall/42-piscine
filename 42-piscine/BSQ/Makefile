GCC = gcc
CFLAG = -Wall -Wextra -Werror
INCLUDE = includes
NAME = bsq
SRCS = srcs/check.c srcs/file.c srcs/main.c srcs/solve.c srcs/util.c
OBJS = ${SRCS:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	$(GCC) $(CFLAG) -o $(NAME) $(OBJS)

.c.o :
	$(GCC) $(CFLAG) -c $< -o $@ -I $(INCLUDE)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re