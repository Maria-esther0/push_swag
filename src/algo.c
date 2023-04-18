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

//int bit_size(int maxi);

// avoir la taille max de l'index
static int    bit_size(int size)
{
	int    bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}

int	max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = tmp->data;
	while (tmp->next)
	{
		if (max < tmp->next->data)
		{
			max = tmp->next->data;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	check_neg(t_list *stack_a)
{
	int	size;
	int	length;

	size = ft_lstsize(stack_a);
	length = 0;
	while (stack_a)
	{
		if (stack_a->data <= 0)
			break ;
		stack_a = stack_a->next;
		length++;
	}
	if (length < size)
		return (1);
	return (0);
}

t_list	*new_list(t_list *stack_a)
{
	int min_value = INT_MAX; // Obtenir la valeur minimale dans la liste
	t_list *current = stack_a;
	while (current != NULL)
	{
		if (current->data < min_value)
			min_value = current->data;
		current = current->next;
	}
	current = stack_a; // Réinitialiser le pointeur 'current' au début de la liste
	while (current != NULL) // Parcourir la liste à nouveau et re-définir les valeurs de chaque élément
	{
		if (current->data >= INT_MAX || current->data <= INT_MIN)
			return (NULL);
		int old_value = current->data;
		int new_value = old_value - min_value + 1; // Ajuster les nouvelles valeurs
		current->data = new_value;
		current = current->next;
	}
	current = stack_a;
	stack_a = current;
	return (stack_a);
}

void    algo(t_list **stack_a, t_list **stack_b)
{
	t_utils utils;

	utils.j = 0;
    utils.tmp = *stack_a;
	utils.len = ft_lstsize(*stack_a);
	if (check_neg(utils.tmp))
	{
		if (!(*stack_a = new_list(utils.tmp)))
			exit(1);
	}
	utils.maxi = max(*stack_a);
	while (utils.j <= bit_size(utils.maxi))
    {
        utils.i = 0;
        while (utils.i < utils.len && is_sorted(*stack_a))
        {
          	utils.tmp = *stack_a;
			if (utils.tmp == NULL)
                printf("stack a est vide\n");
			if (((utils.tmp->data >> utils.j) & 1) == 0)
				pb(&*stack_a, &*stack_b);
			else
				ra(&*stack_a);
			utils.i++;
        }
		while (*stack_b != NULL)
            pa(&*stack_a, &*stack_b);
		utils.j++;
    }
}

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}
