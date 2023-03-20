/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:27:43 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/02 12:11:06 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Alloue (avec malloc(3)) et renvoie un nouvel élément. La variable membre 
’content’ est initialisée à l’aide de la valeur du paramètre ’content’. 
La variable ’next’ est initialisée à NULL.
content: Le contenu du nouvel élément.
declaramos un puntero a un nuevo nodo de la lista, reservamos memoria para el
nuevo nodo usando malloc, que contendra el tamaño en bytes de la estructura
t_list, establecemos el puntero content del nuevo nodo para que apunte al
nuevo elemento que queremos adicionar, luego establecemos el puntero next
del muevo nodo como NULL ya que este es el ultimo nodo de la lista, finalmente
devolvemos el puntero al nuevo nodo creado*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}
