/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:00 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/12 16:25:57 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	arrange_2_arg(t_list **stack_a)
{
	sa(stack_a);
}

void	first_case(t_list **a)
{
	rra(a);
	sa(a);
}

void	second_case(t_list **a)
{
	ra(a);
	sa(a);
}

void	arrange_3_arg(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first < second && second > third && first < third)
		first_case(stack_a);
	else if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first > second && second > third)
		second_case(stack_a);
	else if (first < second && second > third && first > third)
		rra(stack_a);
}
