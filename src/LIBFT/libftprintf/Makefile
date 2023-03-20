CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

OBJS	= ${SRCS:.c=.o}

SRCS	=	ft_printf.c \
			ft_put_c.c \
			ft_put_d_i.c \
			ft_put_p.c \
			ft_put_s.c \
			ft_put_u.c \
			ft_put_x.c \
			ft_check_type.c\


%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<

${NAME}: ${OBJS}
#		$(CC) $(CFLAGS) $(SRCS) -o ft_printf
		ar rcs $(NAME) $(OBJS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re 
