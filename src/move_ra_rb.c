/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ra_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:12 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/05 11:11:59 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "LIBFT/ft_libft/libft.h"

//premier element devient le dernier
static void rotate(t_list **stack)
{
    t_list  *top;

    top = *stack;
    if((*stack) == NULL || ((*stack)->next) == NULL)
    {
        print_list(stack);
        exit(1);
    }
    *stack = top->next;
    top->next = NULL;
    ft_lstlast(*stack)->next = top;
}

void    ra(t_list **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_list **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}

t_list  *ft_lstlast(t_list *list)
{
    t_list	*last;

	last = list;
	while (last->next)
		last = last->next;
	return (last);
}
