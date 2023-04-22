/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <mario@student.42.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:04:41 by Mario             #+#    #+#             */
/*   Updated: 2023/04/20 19:06:44 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_neg(t_list *stack_a)
{
	int	size;
	int	length;

	size = ft_lstsize(stack_a);
	length = 0;
	while (stack_a)
	{
		if (stack_a->data <= 0)
			break ;
		stack_a = stack_a->next;
		length++;
	}
	if (length < size)
		return (1);
	return (0);
}

// copyright <|°_°|>
int	check_if(const char *arg)
{
	int	index;
	int	number;

	index = 0;
	number = 0;
	while (arg[index] == '-' || (ft_isdigit(arg[index]) && index <= 10))
	{
		if (index == 9 && ((number > 214748364)
				|| (number == 214748364 && arg[index] > '7')))
			return (1);
		number = arg[index] - '0' + number * 10;
		index++;
	}
	if (arg[index] != 0)
		return (1);
	return (0);
}

int	check_one_arg(char **argv, t_utils	*utils)
{
	utils->n = 0;
	utils->tp = ft_split(argv[1], ' ');
	utils->tp2 = ft_split(argv[1], ' ');
	while (utils->tp[utils->j])
	{
		utils->x = 0;
		utils->count = 0;
		utils->temp = utils->tp[utils->n];
		while (utils->tp2[utils->i])
		{
			if (!ft_strncmp(utils->temp, utils->tp2[utils->x],
					ft_strlen(utils->tp2[utils->x]))
				&& (ft_strlen(utils->tp2[utils->x])
					== ft_strlen(utils->temp)))
			{
				utils->count++;
				if (utils->count >= 2)
					return (1);
			}
			utils->x++;
		}
		utils->n++;
	}
	return (0);
}
