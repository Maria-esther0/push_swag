cmake_minimum_required(VERSION 3.22)
project(push_swag C)

set(CMAKE_C_STANDARD 11)

SET(LIBS ft ftprintf)

SET(LIBS ${LIBS})

include_directories(includes)
include_directories(src/LIBFT/ft_libft)
include_directories(src/LIBFT/get_next_line)
include_directories(src/LIBFT/libftprintf)

link_directories(src/LIBFT/ft_libft src/LIBFT/libftprintf)

add_executable(
        push_swag
        src/algo.c
        src/arrange_big_stack.c
        src/arrange_small_stack.c
        src/free.c
        src/main.c
        src/move_pa_pb.c
        src/move_ra_rb.c
        src/move_rra_rrb.c
        src/move_sa_sb.c
        src/push_swap.c
#        src/quick_sort.c
        src/stack_a_is_sorted.c
#        trash/test2.c
#        trash/tester_quickSort.c
)

TARGET_LINK_LIBRARIES(push_swag ${LIBS})
