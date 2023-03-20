/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pa_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:18:16 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/16 16:31:54 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//prend le premier element du sommet d'une stack et le met sur l'autre
//ne fait rien si l'autre stack est vide

void	pa(t_data	**stack_a, t_data	**stack_b)
{
	t_data	*push_b;

    if (!stack_b)
        exit(1);
    push_b = (*stack_b)->next;
    (*stack_b)->next = *stack_a;
    //push_b = *stack_a;
    *stack_a = *stack_b;
    *stack_b = push_b;
    write(1, "pa\n", 3);
}

void    pb(t_data **stack_a, t_data **stack_b)
{
    t_data  *push_a;

    if (!stack_a)
        exit(1);
    push_a = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = push_a;
    write(1, "pb\n", 3);
}
