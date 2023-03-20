/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:45:53 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/03 12:01:35 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Libère la mémoire de l’élément passé en argument en utilisant la fonction
’del’ puis avec free(3). La mémoire de ’next’ ne doit pas être free.
lst: L’élément à free
del: L’adresse de la fonction permettant de supprimer le contenu de l’élément.
elimina el unico nodo de una lista enlazada, primero liberando la memoria
del contenido del nodo y luego liberando la memoria del nodo en si mismo*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free (lst);
}
