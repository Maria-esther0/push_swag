/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:17:39 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/06 22:52:57 by mariavillar      ###   ########.fr       */
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

/*void    algo(t_list *stack_a, t_list *stack_b, int size)
{
    (void)size;
    int i;
    int j;
    int maxi;
    int len;
    t_list *tmp;

    j = 0;
    tmp = stack_a;
    maxi = max(stack_a);
    len = ft_lstsize(stack_a);
   printf("len_algo:%d\n", len);
    //while (j <= (size -1) || bit_size(size))
    while (j <= bit_size(maxi))
    {
        //printf("boucle j\n");
        i = 0;
       // while (i < size)
        while (i < len)
        { 
            //printf("boucle i\n");
            tmp = stack_a;
            if (stack_a == NULL)
                printf("stack a est vide\n");
            //if ((j >> i) & (j == 0))
            if (((tmp->data >> j) & 1)== 1)
            {
               // printf("ca rentre dans la premiere boucle\n");
                pb(&stack_a, &stack_b);
                // printf("%d\n", stack_b == NULL);
            }
            else 
            {
               // printf("ca rentre dans la deuxieme boucle\n");
                ra(&stack_a);
                printf("%d\n", stack_b == NULL);
            }
            i++;
           // printf("BBBBB\n");
        }
       // ft_printf("AAAA\n");
        // printf("%d\n", stack_b == NULL);
        while (stack_b != NULL)
        {
            printf("ca rentre dans la troisieme boucle \n");
            pa(&stack_a, &stack_b);
        }
        j++;
        display_lst(&stack_a, "stack_a");
        display_lst(&stack_b, "stack_b");
    }
    printf("SORTIE\n");
}*/

void    algo(t_list *stack_a, t_list *stack_b)
{
	t_utils utils;

	utils.j = 0;
    utils.tmp = stack_a; // ERROR: No es necesario asignar 'tmp' a 'stack_a' aquí, ya que no se utiliza hasta más adelante en el bucle.
    utils.maxi = max(stack_a);
    utils.len = ft_lstsize(stack_a);
    while (utils.j <= bit_size(utils.maxi))
    {
        utils.i = 0;
        while (utils.i < utils.len)
        {
            utils.tmp = stack_a; // ERROR: Esto no hace nada útil, ya que 'stack_a' no cambia.
            if (stack_a == NULL) // ERROR: Esto siempre es falso, ya que 'stack_a' nunca es nulo aquí. Debería ser 'if (tmp == NULL)'.
                printf("stack a est vide\n");
            else if (((utils.tmp->data >> utils.j) & 1)== 0) // ERROR: Estás comprobando el primer bit del primer elemento de la lista en lugar del i-ésimo elemento.
                pb(&stack_a, &stack_b);
                // ra(&stack_a); // ERROR: No necesitas rotar 'stack_a' aquí.
            else
                ra(&stack_a); // ERROR: No necesitas rotar 'stack_a' aquí.
				// pb(&stack_a, &stack_b);
			utils.i++;
        }
        while (stack_b != NULL)
            pa(&stack_a, &stack_b);
		utils.j++;
    }
	display_lst(&stack_a, "stack_a");
	display_lst(&stack_b, "stack_b");
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