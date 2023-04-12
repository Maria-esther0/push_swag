///* ************************************************************************** */
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
void    arrange_5_arg(t_list    **stack_a, t_list   **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	arrange_3_arg(stack_a);
	pa(stack_a, stack_b);
	fisrt_pa_5arg(stack_a);
	pa(stack_a, stack_b);
	second_pa_5arg(stack_a);
}

void    fisrt_pa_5arg(t_list    **stack_a)
{
	int first = (*stack_a)->data;
	int second = (*stack_a)->next->data;
	int third = (*stack_a)->next->next->data;
	int	fourth = (*stack_a)->next->next->next->data;

	// printf("ca rentre dans la fct first_pa_5_arg\n");
    global_move(stack_a);
    if (((first > second) && (first > third)) && (first < fourth))
    {
        rra(stack_a);
        sa(stack_a);
        ra(stack_a);
        ra(stack_a);
    }
}

void	second_pa_5arg(t_list **stack_a)
{
	int first = (*stack_a)->data;
	int second = (*stack_a)->next->data;
	int third = (*stack_a)->next->next->data;
	int	fourth = (*stack_a)->next->next->next->data;
	int fifth = (*stack_a)->next->next->next->next->data;

	global_move(stack_a);
	if (((first > second) && ((first > third) && (first > fourth))) && (first < fifth)) // 4 | 1 2 3 x 5
	{
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	else if (((first > second) && (first > third)) && ((first < fourth) && (first < fifth))) // 3 | 1 2 x 4 5
	{
		rra(stack_a);
		sa(stack_a);
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
}
// if 2nd arg is smaller than 1st, then we swap in both cases(1st & 2nd pa),
// if 1st is bigger than last arg, we ra in both cases 
void    global_move(t_list  **stack_a)
{
	int fifth = 0;
	if (get_stack_size(*stack_a) == 5)
		fifth = (*stack_a)->next->next->next->next->data;
    int first = (*stack_a)->data;
	int second = (*stack_a)->next->data;
	int third = (*stack_a)->next->next->data;
	int	fourth = (*stack_a)->next->next->next->data;

    if (((first > second) && (first > third) && (first > fourth) && (first > fifth)) || ((first > second) && (first >third) && (first > fourth)))
        	ra(stack_a);
    else if (((first > second) && (first < third && (first < fourth) && (first < fifth))) || ((first > second) && ((first < third) && (first < fourth))))
        	sa(stack_a);
	else
		return ;
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
