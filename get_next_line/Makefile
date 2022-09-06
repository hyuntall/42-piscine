NAME		=	get_next_line.a


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= get_next_line.c \
			get_next_line_utils.c \

BSRCS	= get_next_line_bonus.c \
			get_next_line_utils_bonus.c \

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

ifdef WITH_BONUS
	OBJFILES = $(OBJS) $(BOBJS)
else
	OBJFILES = $(OBJS)
endif
.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJFILES)
	ar -rc $@ $^

bonus :
	@make WITH_BONUS=1 all

all : $(NAME)

clean:
	@rm -f $(OBJS) $(BOBJS)

fclean:		clean
	@rm -f $(NAME)

re : clean all

.PHONY : all clean fclean re bonus%