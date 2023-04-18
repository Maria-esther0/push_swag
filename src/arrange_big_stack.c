/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:11 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/21 18:50:29 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int min_stack(t_list *tmp, int *ind)
{
	int i = tmp->data;
	int t = 0;

	while (tmp)
	{
		if (tmp->data < i)
		{
			i = tmp->data;
			(*ind) = t;
		}
		t++;
		tmp = tmp->next;
	}
	return (i);
}

void    arrange_5_arg(t_list    **stack_a, t_list   **stack_b)
{
	int min;
	t_list *tmp;
	int p;
	int index;

	index = 0;
	min = 0;
	tmp = *stack_a;
	p = 0;
	min = min_stack(tmp, &index);
	while (p != 2)
	{
		if ((*stack_a)->data == min)
        {
            pb(stack_a, stack_b);
            tmp = *stack_a;
            min = min_stack(tmp, &index);
            p++;
        }
		if (index > 2) {
			rra(stack_a);
		} else {
			ra(stack_a);
		}
    }
    arrange_3_arg(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

void    arrange_4_arg(t_list **stack_a, t_list **stack_b)
{
	pb(stack_a, stack_b);
	arrange_3_arg(stack_a);
	pa(stack_a, stack_b);
	util_4_arg(stack_a);
}

void	util_4_arg(t_list **stack_a)
{
	int first = (*stack_a)->data;
	int second = (*stack_a)->next->data;
	int third = (*stack_a)->next->next->data;
	int	fourth = (*stack_a)->next->next->next->data;

	if ((first > second) && (first > third) && (first < fourth))
	{
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	else if ((first < third) && (first < fourth) && (first > second))
		sa(stack_a);
	else if ((first > second) && (first > third))
		ra(stack_a);
}
