/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rra_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:17 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/15 20:34:34 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//le dernier element devient le premier
static void rev_rot(t_data **stack)
{
    t_data  *x;
    t_data  *last;

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

void    rra(t_data  **stack_a)
{
    rev_rot(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_data  **stack_b)
{
    rev_rot(stack_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_data **stack_a, t_data **stack_b)
{
    rev_rot(stack_a);
    rev_rot(stack_b);
    write(1, "rrr\n", 4);
}
