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

// at first, we push the first 2 numbers on stack b, then we use the fonction
// that sorts 3 args, then we push on stack a once, we put it on the right spot
// then we repeat the process once again and voila :D
//t_list *current = *stack_a;
//int i = 0;
//while (current != NULL)
//{
//printf("[%d] %d ", i, current->data);
//current = current->next;
//i++;
//}

//int max_stack(t_list *tmp)
//{
//	int i = tmp->data;
//	while (tmp)
//	{
//		printf("%d\n", tmp->data);
//		if (tmp->data > i)
//			i = tmp->data;
//		tmp = tmp->next;
//	}
//	return (i);
//}

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
	else if (first < (third && fourth) && first > second)
		sa(stack_a);
	else if (first > (first && second && third))
		ra(stack_a);
}
