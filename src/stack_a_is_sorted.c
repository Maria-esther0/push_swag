/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:16 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/06 16:53:49 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

int	is_sorted(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	display_lst(t_list **ptr_to_head, char *name)
{
	t_list	*current_node;
	int		count;

	current_node = *ptr_to_head;
	count = 0;
	ft_printf("\n%s :\n", name);
	if (*ptr_to_head != NULL)
	{
		while (current_node->next != NULL)
		{
			ft_printf("Index = %d : ", count);
			display_node(current_node);
			current_node = current_node->next;
			count++;
		}
		ft_printf("Index = %d : ", count);
		display_node(current_node);
	}
	else
		ft_printf("The stack is empty.\n");
	ft_printf("\n");
}

void	display_node(t_list *lst)
{
	if (lst != NULL)
	{
		ft_printf("[%p] {value = %d | indice = %d | nx = %p}\n", lst,
			lst->data,
			lst->data,
			lst->next);
	}
}
