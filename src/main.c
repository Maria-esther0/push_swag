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

int main(int argc, char *argv[])
{
    if (argc <= 2)
    {
	    printf("usage: ./push_swap <int arguments>\n");
	    return (EXIT_FAILURE);
    }
    t_list  *a = NULL;
    t_list  *b = NULL;
    fill_stack(&a, argv);
    (void)b;
	if (!is_sorted(a))
	{
		printf("Already sorted\n");
		return 0;
    }
	int size = get_stack_size(a);
	if (size == 3)
		arrange_3_arg(&a);
	print_list(&a);
	free_list_a(a);
	free_list_b(b);
   return (0);
}
