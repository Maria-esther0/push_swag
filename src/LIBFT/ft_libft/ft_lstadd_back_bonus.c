/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:21:44 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/02 15:31:45 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ajoute l’élément ’new’ à la fin de la liste.
lst: L’adresse du pointeur vers le premier élément de la liste.
new: L’adresse du pointeur vers l’élément à rajouter à la liste. 
declaramos un puntero a un nuevo nodo de la lista, buscamos el ultimo elemento
de la lista con la funcion ft_lstlast, si el ultimo elemento es NULL, no hay
ninguna lista, por lo que establecemos el puntero de la lista para que apunte
al nuevo elemento, finalmente establecemos el ultimo elemento en la nueva
variable*/

//*[je][suis][sus][0]
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	last->next = new;
}
