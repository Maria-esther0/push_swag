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

	new_node = (t_list *) malloc(sizeof(t_list));
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

int	check_similaire(int ac, char **argv, const char *tmp, t_utils *utils)
{
	utils->i = 0;
	utils->count = 0;
	if (ac == 2)
	{
		if (check_one_arg(argv, utils))
		{
			ft_printf("Error\n");
			return (1);
		}
	}
	while (argv[utils->i])
	{
		if (!ft_strncmp(tmp, argv[utils->i], ft_strlen(argv[utils->i]))
			&& (ft_strlen(argv[utils->i]) == ft_strlen(tmp)))
		{
			utils->count++;
			if (utils->count >= 2)
			{
				ft_printf("Error\n");
				return (1);
			}
		}
		utils->i++;
	}
	return (0);
}

int	set_node(t_list **a, char *arg, t_utils utils)
{
	utils.i = -1;
	utils.args = ft_split(arg, ' ');
	if (utils.args == NULL)
		return (1);
	utils.res = 0;
	while (utils.args[++utils.i])
	{
		if (check_if(utils.args[utils.i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		utils.err = my_atoi(utils.args[utils.i], &utils.ret);
		if (utils.err == 1 && utils.ret != 1)
		{
			ft_printf("Error");
			exit(1);
		}
		utils.res = insert(a, utils.ret);
		if (utils.res != 0)
			break ;
	}
	free_strs(utils.args);
	return (utils.res);
}

int	fill_stack(t_list **a, int ac, char **argv)
{
	int		i;
	char	*tmp;
	t_utils	utils;

	i = 1;
	while (argv[i])
	{
		if (set_node(a, argv[i], utils))
		{
			ft_printf("Error\n");
			return (1);
		}
		tmp = argv[i];
		if (check_similaire(ac, argv, tmp, &utils))
			exit(1);
		i++;
	}
	return (0);
}
