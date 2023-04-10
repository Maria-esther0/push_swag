CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

#OBJS	= ${SRCS:.c=.o}
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

SRCS	=	ft_printf.c \
			ft_put_c.c \
			ft_put_d_i.c \
			ft_put_p.c \
			ft_put_s.c \
			ft_put_u.c \
			ft_put_x.c \
			ft_check_type.c\


#%.o: %.c
#		$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: %.c
	mkdir -p obj/src
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
#	$(CC) $(CFLAGS) $(SRCS) -o ft_printf
	ar rcs $(NAME) $(OBJS)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all fclean clean re 
