/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:17:39 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/03 17:40:07 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static int    bit_size(int size);

void    algo(t_list *stack_a, t_list *stack_b, int num)
{
    int i;
    int j;

    j = 0;
    while (j <= (num -1) || bit_size(num))
    {
        i = 1;
        while (i < num)
        {
            if (j >> i & (j == 0))
                pb(&stack_a, &stack_b);
            else
                ra(&stack_a);
            i++;
        }
    }
}

 // avoir la taille max de l'index 
static int    bit_size(int size)
{
    int    bit_max;

    bit_max = 0;
    //while (size > (1U << bit_max))
    while (size >> bit_max)
        bit_max++;
    return (bit_max);
}

// void    algo(t_list *stack_a, t_list *st
// {
    // int i;
    // int j;
// 
    // j = 0;
    // while (j >= (num -1))
    // {
        // i = 1;
        // while (i < num)
        // {
            // if (j >> i & 1 == 0)
                // pa(&stack_a, &stack_b);
            // else
                // ra(&stack_a);
            // i++;
        // }
    // }
// }
