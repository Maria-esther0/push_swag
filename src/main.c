/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:28:50 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/22 17:29:45 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_stack_size(t_list *a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_sign(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	while (av[i])
	{
		j = 0;
		count = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				count++;
			if (count > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_first(const char *av1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av1[i])
	{
		if (av1[i] == ' ')
			j++;
		i++;
	}
	if (j == i)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

void	tri_algo(t_list *a, t_list *b, t_utils *utils)
{
	int		size;

	size = get_stack_size(a);
	while (size)
	{
		if (!is_sorted(a))
			break ;
		else if (size == 2)
			arrange_2_arg(&a);
		else if (size == 3)
			arrange_3_arg(&a);
		else if (size == 4)
			arrange_4_arg(&a, &b);
		else if (size == 5)
			arrange_5_arg(&a, &b);
		else
			algo(&a, &b, utils);
	}
	display_lst(&a, "stack_a");
	free_list_a(a);
	free_list_b(b);
}

int	main(int argc, char *argv[])
{
	t_utils	utils;
	t_list	*a;
	t_list	*b;

	if (argc <= 1 || !ft_strlen(argv[1]) || check_first(argv[1]))
		return (EXIT_FAILURE);
	if (check_sign(argv))
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	fill_stack(&a, argc, argv);
	if (!is_sorted(a))
		return (0);
	tri_algo(a, b, &utils);
	return (0);
}
