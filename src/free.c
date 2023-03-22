/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:04:29 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/22 10:36:30 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list_a(t_list *head)
{
	t_list *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = NULL;
		head = tmp;
	}
}
