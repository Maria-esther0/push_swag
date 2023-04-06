/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rra_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:17 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/06 23:40:01 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "LIBFT/ft_libft/libft.h"

//le dernier element devient le premier
static void rev_rot(t_list **stack)
{
	t_list	*last;
    t_list  *new_element;

    if (!stack || !(*stack) || !(*stack)->next);
        return ;
    last = *stack;
    while (last->next && last->next->next)
		last = last->next;

    new_element = last->next;
    ft_lstadd_front(stack, new_element);
    last->next = NULL;
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
void	ft_lstadd_front(t_list **lst, t_list *new)
{
    if(!(*lst))
        exit(EXIT_FAILURE);
	new->next = *lst;
	*lst = new;
}
