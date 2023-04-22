/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:04:29 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/30 14:44:50 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list_a(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}

void	free_list_b(t_list	*head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}

/* frees a NULL-terminated array of strings */
void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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

int	max(t_list *stack)
{
	t_list	*tmp;
	int		max;

	tmp = stack;
	max = tmp->data;
	while (tmp->next)
	{
		if (max < tmp->next->data)
			max = tmp->next->data;
		tmp = tmp->next;
	}
	return (max);
}
