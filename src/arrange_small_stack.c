/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:45:00 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/03 17:02:13 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    arrange_2_arg(t_list    **stack_a)
{
    // if ((*stack_a)->data > (*stack_a)->next->data)
    sa(stack_a);
}

void    first(t_utils *utils, t_list **stack_a)
{
    if (utils->second > utils->third)
        sa(stack_a);
    ra(stack_a);
}

void    second(t_utils *utils, t_list **stack_a)
{
    if (utils->first > utils->third)
        ra(stack_a);
    sa(stack_a);
}

void    third(t_utils *utils, t_list **stack_a)
{
    if (utils->first > utils->second)
        sa(stack_a);
    rra(stack_a);
}

void    first_case(t_list **a)
{
    rra(a);
    sa(a);
}

void    second_case(t_list **a)
{
    ra(a);
    sa(a);
}

void     arrange_3_arg(t_list    **stack_a)
{
    int first = (*stack_a)->data;
    int second = (*stack_a)->next->data;
    int third = (*stack_a)->next->next->data;

    // printf("first<%d> second<%d> third<%d>\n", first, second, third);

    if (first < second && second > third && first < third) // 2 10 3 ✅
    {
        // printf("BOUCLE 1\n");
        first_case(stack_a);
    }
    else if (first > second && second < third && first < third) // 3 2 10 ✅
    {
        // printf("BOUCLE 2\n");
        sa(stack_a);
    }
    else if (first > second && second < third && first > third) // 10 2 3 ✅
    {
        // printf("BOUCLE 3\n");
        ra(stack_a);
    }
    else if (first > second && second > third) // 10 3 2 ✅
    {
        // printf("BOUCLE 4\n");
        second_case(stack_a);
    }
    else if (first < second && second > third && first > third) // 3 10 2 ✅
    {
        // printf("BOUCLE 5\n");
        rra(stack_a);
    }
}
   /*t_utils utils;
    utils.first = (*stack_a)->data;
    utils.second = (*stack_a)->next->data;
    utils.third = (*stack_a)->next->next->data;
    if(utils.first < (utils.second && utils.third))   
        first(&utils, stack_a);
    else if (utils.second < (utils.first && utils.third))
        second(&utils, stack_a);
    else if (utils.third < (utils.first && utils.second))
        third(&utils, stack_a);*/
