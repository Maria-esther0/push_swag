/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_big_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:11 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/20 17:02:14 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// at first, we push the first 2 numbers on stack b, then we use the fonction
// that sorts 3 args, then we push on stack a once, we put it on the right spot
// then we repeat the process once again and voila :D
void    arrange_5_arg(t_data    **stack_a, t_data   **stack_b)
{
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
        arrange_3_arg(stack_a);
        pa(stack_a, stack_b);
        fisrt_pa_5arg(stack_a);
        second_pa_5arg(stack_a);
}

void    fisrt_pa_5arg(t_data    **stack_a)
{
    t_utils i;

    global_move(stack_a);
    if ((i.first > (i.second && i.third)) && (i.first < i.fourth))
    {
        rra(stack_a);
        sa(stack_a);
        ra(stack_a);
        ra(stack_a);
    }
}

void    second_pa_5arg(t_data   **stack_a)
{
    t_utils i;
    
    global_move(stack_a);
    if ((i.first > (i.second && i.third && i.fourth)) && (i. first < i.fifth))
    {
        rra(stack_a);
        sa(stack_a);
        ra(stack_a);
        ra(stack_a);
    }
    else if ((i.first > (i.second && i.third)) && (i.first < (i.fourth && i.fifth)))
        rra(stack_a);
        sa(stack_a);
        rra(stack_a);
        sa(stack_a);
        ra(stack_a);
        ra(stack_a);
        ra(stack_a);
}

// if 2nd arg is less than 1st, then we swap in both cases(1st & 2nd pa),
// if 1st is bigger than last arg, we ra in both cases 
void    global_move(t_data  **stack_a)
{
    t_utils i;

    if (i.first > (i.second && i.third && i.fourth && i.fifth) || 
        (i.first > (i.second && i.third && i.fourth)))
        ra(stack_a);
    if (((i.first > i.second) && (i.first < (i.third && i.fourth && i.fifth))) ||
        ((i.first > i.second) && (i.first < (i.third && i.fourth))))
        sa(stack_a);
}
