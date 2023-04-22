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

int	insert(t_list **a, int number)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (-1);
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

//int	check_similaire2(t_utils utils, char **argv, const char *tmp)
//{
//
//	if (!ft_strncmp(tmp, argv[utils.i], ft_strlen(argv[utils.i]))
//		&& (ft_strlen(argv[utils.i]) == ft_strlen(tmp)))
//	{
//		utils.count++;
//		if (utils.count >= 2)
//		{
//			printf("error\n");
//			return (1);
//		}
//		utils.i++;
//	}
//	return (0);
//}

int	check_similaire(int ac, char **argv, const char *tmp)
{
	t_utils	utils;

	utils.i = 0;
	utils.count = 0;
	if (ac == 2)
	{
		if (check_one_arg(argv, utils))
		{
			ft_printf("error\n");
			return (1);
		}
	}
	while (argv[utils.i])
	{
		if (!ft_strncmp(tmp, argv[utils.i], ft_strlen(argv[utils.i]))
			&& (ft_strlen(argv[utils.i]) == ft_strlen(tmp)))
		{
			utils.count++;
			if (utils.count >= 2)
			{
				printf("error\n");
				return (1);
			}
		}
		utils.i++;
	}
	return (0);
}

int	set_node(t_list **a, char *arg)
{
	int		i;
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
			ft_printf("Error\n");
			exit(1);
		}
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
	int		i;
	char	*tmp;

	i = 1;
	while (argv[i])
	{
		if (set_node(a, argv[i]))
		{
			ft_printf("error\n");
			return (1);
		}
		tmp = argv[i];
		if (check_similaire(ac, argv, tmp))
			exit(1);
		i++;
	}
	return (0);
}
