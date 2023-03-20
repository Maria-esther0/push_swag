/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:00 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/18 11:30:50 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    arrange_2_arg(t_data    **stack_a)
{
    if ((*stack_a)->number > (*stack_a)->next->number)
        sa(stack_a);
}

void    first(t_utils *utils, t_data **stack_a)
{
    if (utils->second > utils->third)
        sa(stack_a);
    ra(stack_a);
}

void    second(t_utils *utils, t_data **stack_a)
{
    if (utils->first > utils->third)
        ra(stack_a);
    sa(stack_a);
}

void    third(t_utils *utils, t_data **stack_a)
{
    if (utils->first > utils->second)
        sa(stack_a);
    rra(stack_a);
}

void     arrange_3_arg(t_data    **stack_a)
{
    t_utils utils;

    utils.first = (*stack_a)->number;
    utils.second = (*stack_a)->next->number;
    utils.third = (*stack_a)->next->next->number;
   
    if(utils.first < (utils.second && utils.third))   
        first(&utils, stack_a);
    else if (utils.second < (utils.first && utils.third))
        second(&utils, stack_a);
    else if (utils.third < (utils.first && utils.second))
        third(&utils, stack_a);        
}
