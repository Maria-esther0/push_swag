/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:48:44 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/03 14:07:01 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Supprime et libère la mémoire de l’élément passé en paramètre, et de tous 
les éléments qui suivent, à l’aide de ’del’ et de free(3) Enfin, le pointeur 
initial doit être mis à NULL.
lst: L’adresse du pointeur vers un élément.
del: L’adresse de la fonction permettant de supprimer le contenu d’un élément.
mismo concepto que la funcion delone, pero en vez de remover un elemento,
remueve el elemento pasado como un parametro asi como todos los elementos
siguientes*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free (*lst);
	*lst = NULL;
}
