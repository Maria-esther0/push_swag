/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:54:58 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/03 16:56:44 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Itère sur la liste ’lst’ et applique la fonction ’f ’au contenu de chaque 
élément. Crée une nouvelle liste résultant des applications successives de ’f’.
La fonction ’del’ est là pour détruire le contenu d’un élément si nécessaire.
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
del: L’adresse de la fonction permettant de supprimer le contenu d’un élément.
funciona de la misma manera que lstiter, pero crea una nueva lista resultante de
las aplicaciones sucesivas de f sobre el contenido de cada elemento*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elmnt;

	if (!f || !lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_elmnt = ft_lstnew(lst->content);
		if (!new_elmnt)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elmnt);
		lst = lst->next;
	}
	return (new_lst);
}
