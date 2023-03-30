/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_is_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:16 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/30 16:34:16 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h" 

int is_sorted(t_list *a)
{
    t_list *tmp;
    tmp = a;
    while (tmp->next)
    {
        // if (!tmp->next)
            // break;
        if (tmp->data > tmp->next->data)
            return (1);
        tmp = tmp->next;
    }
    return 0;
}
