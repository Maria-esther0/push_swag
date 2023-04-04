/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:29:27 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/04 20:05:52 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Compte le nombre d’éléments de la liste. lst: Le début de la liste.
la variable l nos servira para medir la longitud del tamaño de la lista,
creamos un bucle, mientras que el puntero a traves de la lista siga avanzando
al siguiente elemento, incrementamos l, al final retornamos l*/

int	ft_lstsize(t_list *lst)
{
	int	l;

	l = 0;
	while (lst)
	{
		lst = lst->next;
		l++;
	}
	return (l);
}
