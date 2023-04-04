/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:17:39 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/04 20:07:09 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
static int    bit_size(int size);
int	ft_lstsize(t_list *lst);

int max(t_list *stack)
{
    t_list *tmp;
	int max;

    tmp = stack;
	max = tmp->data;
	while(tmp->next)
	{
		if (max < tmp->next->data)
		{
			max = tmp->next->data;
		}
		tmp = tmp->next;
	}
    //printf("max:%d\n", max);
	return max;
}

void    algo(t_list *stack_a, t_list *stack_b, int num)
{
    (void)num;
    int i;
    int j;
    int maxi;
    int len;
    t_list *tmp;

    j = 0;
    tmp = stack_a;
    maxi = max(stack_a);
    len = ft_lstsize(stack_a);
   //printf("len_algo:%d\n", len);
    //while (j <= (num -1) || bit_size(num))
    while (j <= bit_size(maxi))
    {
        //printf("boucle j\n");
        i = 0;
       // while (i < num)
        while (i < len)
        { 
            //printf("boucle i\n");
            tmp = stack_a;
            //if ((j >> i) & (j == 0))
            if ((tmp->data >> i & 1)== 0)
            {
               // printf("ca rentre dans la premiere boucle\n");
                pb(&stack_a, &stack_b);
            }
            else if ((tmp->data >> i & 1)== 1)
            {
               // printf("ca rentre dans la deuxieme boucle\n");
                ra(&stack_a);
            }
            i++;
        }
        while (stack_b)
            pa(&stack_a, &stack_b);
        j++;
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

/*
void    radix(t_lst stack_a, t_lst stack_b, int size)
{
    t_lst    tmp;
    int        i;
    int        j;

    i = 0;
    tmp =stack_a;
    while (i < bit_size(size - 1))
    {
        j = 0;
        while (j < size - 1)
        {
            tmp = stack_a;
            if ((tmp->idx >> i & 1) == 0)
                ra(stack_a);
            else if ((tmp->idx >> i & 1) == 1)
                pb(stack_a, stack_b);
            j++;
        }
        while (stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}
*/
 // avoir la taille max de l'index 
static int    bit_size(int size)
{
    int    bit_max;

    bit_max = 0;
    //while (size > (1U << bit_max))
    while (size >> bit_max)
        bit_max++;
    //printf("bit_size;%d\n", bit_max);
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
