/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:28:57 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/05 16:55:17 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

// *[10][NULL]
// a*[NULL]
int	insert(t_list **a, int number)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return -1;
	tmp = *a;	
	new_node->data = number;
	new_node->next = NULL;
	if (*a == NULL)
	{
		new_node->previous = NULL;
		*a = new_node;
		return (0);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->previous = tmp;

	return (0);
}

void	print_list(t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		//printf("--------------\n");
		//printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

// max signed integer for 32 bit 2147483647
// 10 digits
// 123asdf\0 -> 1
// asdf123 -> 1
// 123\0 -> 0
// 0 -> 0
// 2147483647 -> 0
// 2147483648 -> 1


// return 0 if the number is valid
// else return 1
// copyright <|°_°|>
int	check_if(const char* arg)
{
	int index;
	int number;

	index = 0;
	number = 0;
	while (arg[index] == '-' || (ft_isdigit(arg[index]) && index <= 10))
	{
		if (index == 9 && ((number > 214748364) || (number == 214748364 && arg[index] > '7')))
			return 1;
		number = arg[index] - '0' + number * 10;
		index++;
	}
	if (arg[index] != 0)
		return 1;
	return 0;
}

int check_similair(char **argv, const char *tmp)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while(argv[i])
	{
		if (!ft_strncmp(tmp, argv[i], ft_strlen(argv[i])) &&
			(ft_strlen(argv[i]) == ft_strlen(tmp)))
		{
			if (count >= 2) {
				printf("error: similaire = %s\n", argv[i]);
				return (1);
			}
			count++;
		}
		i++;
	}
	return (0);
}

int	set_node(t_list **a, char *arg)
{
	int 	i;
	char	**args;
	int		num;
	int		res;

	i = -1;
	args = ft_split(arg, ' ');
	if (args == NULL)
		return (1);
	res = 0;
	while (args[++i])
	{
		if (check_if(args[i]))
		{
			printf("invalid number: %s\n", args[i]);
			exit(1);
		}
		// atoi bc we need numbers not a string, puis je mets dans ma liste, je cree un node
		num = ft_atoi(args[i]);
		res = insert(a, num);
		if (res != 0)
			break ;
	}
	free_strs(args);
	return (res);
}

int	fill_stack(t_list **a, char **argv)
{
	int i = 1;
	char* tmp;

	while (argv[i])
	{
		if (set_node(a, argv[i]))
		{
			printf("error\n");
			return (1);
		}
		tmp = argv[i];
		if (check_similair(argv, tmp))
			exit(1);
		i++;
	}
//	print_list(a);
	return 0;
}

// int	main(int argc, char **argv)
// {
// 	int	array_of_number[] = {-846, 85, 8786};
// 	int	array_of_number[] = {672, -94, 45, 142, 3};
// 	int	array_of_number[] = {10, 1000, -2, 807416, 898, 3, 5, 1, -345, 89, 56, -3, -3};
// 	if (argc <= 2)
// 	{
// 		printf("usage: ./push_swap <int arguments>\n");
// 		return (EXIT_FAILURE);
// 	}
// 	t_list *a = NULL;
// 	t_list *b = NULL;

// 	fill_stack(&a, argv);
// 	(void)b;
// 	/* sorting here */
// 	if (argc >= 3)
// 	{
// 		algo(a, b, argc -1);
// 		if (argc -1 == 2)
// 			arrange_2_arg(&a);
// 		else if (argc -1 == 3)
// 			arrange_3_arg(&a);
// 		else if (argc -1 == 5)
// 			arrange_5_arg(&a, &b);
// 		algo(a, b, argc -1);
// 	}
// 	free_list_a(a);
// 	if (sizeof(array_of_number) == 5)
// 		arrange_5_arg(&a, &b);
// 	if (sizeof(array_of_number) == 2)
// 		arrange_2_arg(&a);
// 	if (sizeof(array_of_number) == 3)
// 		arrange_3_arg(&a);
// 	int	n = sizeof(array_of_number) / sizeof(array_of_number[0]);

// 	qs_algo(array_of_number, 0, n -1);
// 	printf("el string ordenado es: \n");
// 	print_str(array_of_number, n);
// 	return (0);
// }
