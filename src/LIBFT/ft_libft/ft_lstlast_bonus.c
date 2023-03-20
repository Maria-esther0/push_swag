/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:44:58 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/08 18:59:08 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Renvoie le dernier élément de la liste.
lst: Le début de la liste.
creamos un elemento que va a contener un puntero hacia la lista de elementos, 
luego incrementamos hasta llegar hasta el ultimo elemento de la lista enlazada
y devolvemos el puntero que contiene la direccion del ultimo elemento*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}
// int main(void)
// {
//	t_list	*lst;
// 	t_list	*last;

// 	lst = ft_lstnew("done\n");
// 	ft_lstadd_front(&lst, ft_lstnew("new\n"));
// 	ft_lstadd_front(&lst, ft_lstnew("one\n"));
// 	ft_lstadd_front(&lst, ft_lstnew("first\n"));

// 	last = ft_lstlast(lst);
// 	printf("last = %s\n", (char *)last->content);
// 	return (0);
// }
