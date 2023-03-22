/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:58:47 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/22 10:36:56 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Funcion que devuelve el indice del pivot
int	pivot_index(int str[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = str[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (str[j] < pivot)
		{
			i++;
			ft_swap(&str[i], &str[j]);
		}
		j++;
	}
	ft_swap(&str[i + 1], &str[high]);
	return (i + 1);
}

void	qs_algo(int str[], int low, int high)
{
	int	x;

	if (low < high)
	{
		x = pivot_index(str, low, high);
		qs_algo(str, low, x - 1);
		qs_algo(str, x + 1, high);
	}
}

// Funcion para imprimir la matriz
void	print_str(int str[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", str[i]);
		i++;
	}
	write(1, "\n", 1);
}
// ---------------------------------------------------------- 
// *[10][NULL]
// a*[NULL]
int	insert(t_list **a, int number)
{
	t_list	*new_node;
	t_list	*last;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return -1;
	last = *a;	
	new_node->data = number;
	new_node->next = NULL;
	if (*a == NULL)
	{
		new_node->previous = NULL;
		*a = new_node;
		return (0);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->previous = last;

	return (0);
}

void	print_list(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	printf("-------------------------------------\n");
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("-------------------------------------\n");
}

int	set_node(t_list **a, char *arg)
{
	int 	i = -1;
	char	**args;

	args = ft_split(arg, ' ');
	if (!*args)
		return (-1);
	while (args[++i])
	{
		// atoi bc we need numbers not a string, puis je mets dans ma liste, je cree un node
		int res = ft_atoi(arg);
		if (insert(a, res) != 0)
			return (-1);
		// i++;
	}
	return 0;
}

int	fill_stack(t_list **a, char **argv)
{
	int i = 1;
	while (argv[i])
	{
		if (set_node(a, argv[i]))
			return (-1);
		i++;
	}
	print_list(a);
	return 0;
}

int	main(int argc, char **argv)
{
	// int	array_of_number[] = {-846, 85, 8786};
	// int	array_of_number[] = {672, -94, 45, 142, 3};
	// int	array_of_number[] = {10, 1000, -2, 807416, 898, 3, 5, 1, -345, 89, 56, -3, -3};
	if (argc < 2)
	{
		printf("usage: ./push_swap <int arguments>\n");
		return (EXIT_FAILURE);
	}	
	t_list *a = NULL;

	fill_stack(&a, argv);

	free_list_a(a);
	// if (sizeof(array_of_number) == 5)
		// arrange_5_arg(&a, &b);
	// if (sizeof(array_of_number) == 2)
		// arrange_2_arg(&a);
	// if (sizeof(array_of_number) == 3)
		// arrange_3_arg(&a);
	// int	n = sizeof(array_of_number) / sizeof(array_of_number[0]);
	// t_data *a;
	// t_data *b;
// 
	// qs_algo(array_of_number, 0, n -1);
	// printf("el string ordenado es: \n");
	// print_str(array_of_number, n);
	return (0);
}
