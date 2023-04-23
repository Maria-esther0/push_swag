/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:17:39 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/11 15:55:43 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// avoir la taille max de l'index
static int	bit_size(int size)
{
	int	bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}

void	new_list_second_part(t_list *current, int min)
{
	while (current != NULL)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
}

t_list	*new_list(t_list *stack_a)
{
	int		min_value;
	int		old_value;
	int		new_value;
	t_list	*current;

	min_value = INT_MAX;
	current = stack_a;
	new_list_second_part(current, min_value);
	while (current != NULL)
	{
		if (current->data >= INT_MAX || current->data <= INT_MIN)
			return (NULL);
		old_value = current->data;
		printf("old %d\n", old_value);
		new_value = old_value - min_value + 1;
		printf("new[%d] = old[%d] - min[%d] + 1\n", new_value, old_value, min_value);
		current->data = new_value;
		printf("current %d\n", current->data);
		current = current->next;
	}
	current = stack_a;
	stack_a = current;
	return (stack_a);
}

void	algo_second_part(t_list **stack_a, t_utils *util)
{
	util->tmp = *stack_a;
	if (check_neg(util->tmp))
	{
		if (!(*stack_a == new_list(util->tmp)))
			exit(1);
	}
}

void	algo(t_list **stack_a, t_list **stack_b, t_utils *utils)
{
	utils->j = 0;
	utils->tmp = *stack_a;
	utils->len = ft_lstsize(*stack_a);
	utils->maxi = max(*stack_a);
	algo_second_part(stack_a, utils);
	while (utils->j <= bit_size(utils->maxi))
	{
		utils->i = 0;
		while (utils->i < utils->len && is_sorted(*stack_a))
		{
			utils->tmp = *stack_a;
			if (utils->tmp == NULL)
				ft_printf("error\n");
			if (((utils->tmp->data >> utils->j) & 1) == 0)
				pb(&*stack_a, &*stack_b);
			else
				ra(&*stack_a);
			utils->i++;
		}
		while (*stack_b != NULL)
			pa(&*stack_a, &*stack_b);
		utils->j++;
	}
}
