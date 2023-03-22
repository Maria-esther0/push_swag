/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sa_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:22 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/21 16:32:23 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Ne fait rien s’il n’y en a qu’un ou aucun
static void swap(t_list **stack)
{
    t_list  *x;

    if (!(*stack) || !((*stack)->next))
        exit(1);
    x = *stack;
    *stack = (*stack)->next;
    x->next = (*stack)->next;
    (*stack)->next = x;
}

void    sb(t_list **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    sa(t_list **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}
