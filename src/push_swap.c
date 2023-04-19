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
int	check_one_arg(char **argv)
{	char **tp;
	char **tp2;
	char *tmp;
	int j;
	int count;

	j = 0;
	tp = ft_split(argv[1], ' ');
	tp2 = ft_split(argv[1], ' ');
	while (tp[j])
	{
		int i = 0;
		count = 0;
		tmp = tp[j];
		while (tp2[i]) {
			printf("%s %s\n", tp2[i], tmp);
			if (!ft_strncmp(tmp, tp2[i], ft_strlen(tp2[i])) &&
				(ft_strlen(tp2[i]) == ft_strlen(tmp))) {
				printf("bef %d %s %s\n", count, tp2[i], tmp);
				count++;
				printf("aft %d\n", count);
				if (count >= 2)
					return (1);
			}
			i++;
		}
		j++;
	}
//	j = 0;
//	while(tp[j])
//	{
//		free(argv[j]);
//		tp[j] = NULL;
//	}
//	tp[j] = NULL;
	return (0);
}

int check_similair(int ac, char **argv, const char *tmp) {
	int i;
	int count;

	i = 0;
	count = 0;
	if (ac == 2){
		if (check_one_arg(argv))
		{
			printf("error: similaire = %s\n", argv[i]);
			return (1);
		}
	}

	while (argv[i]) {
		if (!ft_strncmp(tmp, argv[i], ft_strlen(argv[i])) &&
			(ft_strlen(argv[i]) == ft_strlen(tmp))) {
			count++;
			if (count >= 2) {
				printf("error: similaire = %s\n", argv[i]);
				return (1);
			}
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

int	fill_stack(t_list **a, int ac, char **argv)
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
		if (check_similair(ac, argv, tmp))
			exit(1);
		i++;
	}
//	print_list(a);
	return 0;
}
