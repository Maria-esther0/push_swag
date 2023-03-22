/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rra_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:17 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/21 16:56:27 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//le dernier element devient le premier
static void rev_rot(t_list **stack)
{
    t_list  *x;
    t_list  *last;

    if (!(*stack) || !(*stack)->next)
        exit(1);
    x = *stack;
    last = ft_lstlast(*stack);
    while ((*stack)->next->next)
        *stack = (*stack)->next;
    last->next = x;
    (*stack)->next = NULL;
    *stack = x;
}

void    rra(t_list  **stack_a)
{
    rev_rot(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_list  **stack_b)
{
    rev_rot(stack_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rev_rot(stack_a);
    rev_rot(stack_b);
    write(1, "rrr\n", 4);
}
