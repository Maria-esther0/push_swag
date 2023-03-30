/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:23:29 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/30 16:46:03 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef push_swap_h
# define push_swap_h

# include <unistd.h>
# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../src/LIBFT/ft_libft/libft.h"
#include "../src/LIBFT/libftprintf/ft_printf.h"

// typedef struct s_data
// {
    // int index;
    // int n;
    // int f;
    // int number;
// 
// 
    // struct s_data *next;
// }   t_data;

typedef struct s_list
{
    int data;
    struct s_list *next;
    struct s_list *previous;
}       t_list;

typedef struct s_utils
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
}   t_utils;

//quick sort functions
void    QS_algo(int str[], int low, int high);
void    print_str(int str[], int size);
void    ft_swap(int *a, int *b);
int     pivot_index(int str[], int low, int high);
void    arrange_2_arg(t_list    **stack_a);
void    arrange_3_arg(t_list    **stack_a);
void    arrange_5_arg(t_list    **stack_a, t_list   **stack_b);
void    fisrt_pa_5arg(t_list    **stack_a);
void    second_pa_5arg(t_list   **stack_a);
void    global_move(t_list  **stack_a);

// shamefully radix sort
void    algo(t_list *stack_a, t_list *stack_b, int num);
int    is_sorted(t_list *a);
// static int    bit_size(int size);

//moves 
void    pa(t_list **stack_a, t_list **stack_b);
void    pb(t_list **stack_a, t_list **stack_b);
void    sb(t_list **stack_b);
void    sa(t_list **stack_a);
void    ss(t_list **stack_a, t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rra(t_list **stack_a);
void    rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);

//outils
t_list  *ft_lstlast(t_list *list);
t_list  *last_nbr(t_list *list);
void	free_list_a(t_list *head);
void	free_list_b(t_list	*head);
void	free_strs(char **strs);
int	set_node(t_list **a, char *arg);
int	fill_stack(t_list **a, char **argv);
void	print_list(t_list **head);

#endif
