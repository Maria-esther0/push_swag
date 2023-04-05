# # Name of the program
# NAME = push_swap

# LIBFT = libft/libft.a

# PRINTF = libftprintf/ft_printf.a

# # Compiling flags
# FLAGS = -Wall -Werror -Wextra -g

# # Folders
# SRC_DIR = ./src/
# OBJ_DIR = ./obj/
# INC_DIR = ./includes/

# # Sources file and objets files
# SRC_FILES =		src/push_swap.c\
# 				src/quick_sort.c\
# 				src/move_pa_pb.c\
# 				src/move_ra_rb.c\
# 				src/move_sa_sb.c\
# 				src/stack_a_is_sorted.c\
# 				src/free.c\
# 				src/arrange_small_stack.c\
# 				src/arrange_big_stack.c\

# OBJ_FILES = $(SRC_FILES:.c=.o)

# # Pathes
# SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
# OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# # Libft linkers
# LNK = -L $(LIBFT_DIR) -lft

# # All rule
# all :	obj $(NAME)

# obj :
# 		@mkdir -p $(OBJ_DIR)
# 		$(OBJ_DIR)%.o: $(SRC_DIR)%.c

# # Compiling
# $(NAME):	$(OBJ)
# 			@gcc $(OBJ) $(FLAGS) $(LIBFT) $(PRINTF) -lm -o $(NAME)
# 			@echo "Compilation ✅"
# 			@echo "$(NAME) Ready!".

# # bonus: all

# # Clean rule
# clean :
# 			@rm -Rf $(OBJ_DIR)
# 			@echo "Objects removed!"

# # Fclean rule
# fclean : 	clean
# 			@rm -f $(NAME)
# 			@echo "$(NAME) removed!"

# # Re rule
# re :		fclean all

# # Phony
# .PHONY :	all clean fclean re

NAME	= push_swap
LIB		= src/LIBFT/ft_libft/libft.a
LIB2	= src/LIBFT/libftprintf/libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
SRC		= 	src/push_swap.c\
			src/quick_sort.c\
			src/move_pa_pb.c\
			src/move_ra_rb.c\
			src/move_rra_rrb.c\
			src/move_sa_sb.c\
			src/stack_a_is_sorted.c\
			src/free.c\
			src/arrange_small_stack.c\
			src/arrange_big_stack.c\
			src/algo.c\
			src/main.c

OBJ		= $(SRC:.c=.o)

#%.o: %.c
#	$(CC) $(CFLAG) -c $< -o $@
	
all: $(NAME)

$(LIB): 
		make -C src/LIBFT/ft_libft/
		
$(LIB2): 
		make -C src/LIBFT/libftprintf/



$(NAME): $(LIB) $(LIB2) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LIB2) -o $(NAME)
# test:
# 		cd push_swap_tester/ && bash tester.sh ../../push_swap 2 100
# 		cd push_swap_tester/ && bash tester.sh ../../push_swap 3 100
# 		cd push_swap_tester/ && bash tester.sh ../../push_swap 5 100
# 		cd push_swap_tester/ && bash tester.sh ../../push_swap 100 100
# 		cd push_swap_tester/ && bash tester.sh ../../push_swap 500 100

clean:
		rm -rf $(OBJ)
		make -C src/LIBFT/ft_libft clean
		make -C src/LIBFT/libftprintf clean
fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)
		make -C src/LIBFT/ft_libft fclean
		make -C src/LIBFT/libftprintf fclean
re: fclean all