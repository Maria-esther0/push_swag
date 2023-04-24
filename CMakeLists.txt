cmake_minimum_required(VERSION 3.22)
project(push_swag C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(src/LIBFT/ft_libft)
include_directories(src/LIBFT/get_next_line)
include_directories(src/LIBFT/libftprintf)

SET(LIBS ft ftprintf)

#include_directories(libs/libft/incs includes includes/parsing includes/vector
#        includes/rendering/ includes/utils libs/mlx)
link_directories(src/LIBFT/ft_libft src/LIBFT/get_next_line src/LIBFT/libftprintf)

add_executable(
        push_swag
        includes/push_swap.h
        src/algo.c
        src/arrange_big_stack.c
        src/arrange_small_stack.c
        src/free.c
        src/main.c
        src/move_pa_pb.c
        src/move_ra_rb.c
        src/move_rra_rrb.c
        src/move_sa_sb.c
        src/my_atoi.c
        src/push_swap.c
        src/stack_a_is_sorted.c
        src/utils1.c
)

target_link_libraries(push_swag ${LIBS})