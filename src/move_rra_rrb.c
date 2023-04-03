/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rra_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:17 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/03 17:28:19 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

//le dernier element devient le premier
static void rev_rot(t_list **stack)
{
	t_list	*last;

    if (stack == NULL)
        exit(1);
	last = *stack;
    if (last == NULL || (last && last->next == NULL))
        return ;

	while (last->next && last->next->next)
		last = last->next;
    ft_lstadd_front(stack, last->next);
    last->next = NULL;
	return;
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
