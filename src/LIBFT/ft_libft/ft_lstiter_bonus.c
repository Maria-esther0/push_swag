/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:49:34 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/03 15:09:56 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu chaque 
élément.
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
se aplica una funcion f a cada uno de los nodos de una lista enlazada, y recorre
cada nodo de la lista y llama a la funcion f con el contenido del nodo en cada
iteracion*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
