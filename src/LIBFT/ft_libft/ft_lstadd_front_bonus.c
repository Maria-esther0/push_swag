/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:26:33 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/02 12:26:43 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Ajoute l’élément ’new’ au début de la liste.
lst: L’adresse du pointeur vers le premier élément
de la liste.
new: L’adresse du pointeur vers l’élément à
rajouter à la liste.
el puntero next del nuevo nodo se establece como el primer elemento actual de
la lista, luego el puntero de la lista se actualiza para apuntar al nuevo
nodo que ahora es el primer elemento de la lista*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
