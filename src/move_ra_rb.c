/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ra_rb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:36:12 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/08 18:45:58 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "LIBFT/ft_libft/libft.h"

//premier element devient le dernier
static void rotate(t_data **stack)
{
    t_data  *top;

    top = *stack;
    if(!(*stack) || !((*stack)->next))
        exit(1);
    *stack = top->next;
    top->next = NULL;
    ft_lstlast(*stack);
}

void    ra(t_data **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void    rb(t_data **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void    rr(t_data **stack_a, t_data **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}

t_data  *ft_lstlast(t_data *list)
{
    t_data	*last;

	last = list;
	while (last->next)
		last = last->next;
	return (last);
}
