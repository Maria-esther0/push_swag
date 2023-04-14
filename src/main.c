/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ 
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:33:38 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/30 16:46:16 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_stack_size(t_list *a)
{
    t_list *tmp;
    int i;

    i = 0;
    tmp = a;
    while (tmp)
    {
        i++;
		tmp = tmp->next;
    }
    return (i);
}

//void	for_size(int size, t_list *a, t_liste *b)
//{
//	size = get_stack_size(stack_a)
//}


int main(int argc, char *argv[])
{
    int size;

    if (argc <= 1)
	    return (EXIT_FAILURE);
    t_list  *a = NULL;
    t_list  *b = NULL;
    fill_stack(&a, argv);
	(void)b;
	if (!is_sorted(a))
	{
		printf("error\n"); // Already sorted
		return 0;
    }
	size = get_stack_size(a);
	while (size)
    {
        if (!is_sorted(a))
            break ;
		else if (size == 2)
            arrange_2_arg(&a);
        if (size == 3)
			arrange_3_arg(&a);
        else if (size == 4)
		{
            arrange_4_arg(&a, &b);
			// display_lst(&a, "after 4");
		}
        else if (size == 5)
		{
            arrange_5_arg(&a, &b);
		}
        else
            algo(&a, &b);
		// display_lst(&a, "after 5");
//        size--;
    }
	// print_list(&a);
    display_lst(&a, "stack_a");
	free_list_a(a);
	free_list_b(b);
   return (0);
}

