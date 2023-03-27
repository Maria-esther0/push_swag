/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:58:47 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/27 18:39:19 by mvillarr         ###   ########.fr       */
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
 