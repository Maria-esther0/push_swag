/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:23:29 by mvillarr          #+#    #+#             */
/*   Updated: 2023/04/12 17:06:53 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include "../src/LIBFT/ft_libft/libft.h"
# include "../src/LIBFT/libftprintf/ft_printf.h"

typedef struct s_utils
{
	t_list	*tmp;
	t_list	*current;
	t_list	*check;
	char	**args;
	int		err;
	int		res;
	int		ret;
	int		min_value;
	int		i;
	int		j;
	int		maxi;
	int		len;
	int		neg_mask;

	char	**tp;
	char	**tp2;
	char	*temp;
	int		n;
	int		count;
	int		x;

	int		first;
	int		second;
	int		third;
	int		fourth;
	int		fifth;
}	t_utils;

//algorithm

void	ft_swap(int *a, int *b);
void	arrange_2_arg(t_list **stack_a);
void	arrange_3_arg(t_list **stack_a);
void	arrange_4_arg(t_list **stack_a, t_list **stack_b);
void	arrange_5_arg(t_list **stack_a, t_list **stack_b);
void	util_4_arg(t_list **stack_a);
void	first_case(t_list **a);
void	second_case(t_list **a);
int		get_stack_size(t_list *a);
void	algo(t_list **stack_a, t_list **stack_b, t_utils *utils);
int		is_sorted(t_list *a);
int		max(t_list *stack);

//moves 
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_b);
void	sa(t_list **stack_a);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

//outils
t_list	*ft_lstlast(t_list *list);
t_list	*last_nbr(t_list *list);
void	free_list_a(t_list *head);
void	free_list_b(t_list	*head);
void	free_strs(char **strs);
int		set_node(t_list **a, char *arg, t_utils utils);
int		fill_stack(t_list **a, int ac, char **argv);
void	print_list(t_list **head);
void	display_lst(t_list **ptr_to_head, char *name);
void	display_node(t_list *lst);
int		ft_lstsize(t_list *lst);
int		check_similaire(int ac, char **argv, const char *tmp, t_utils *utils);
int		check_one_arg(char **argv, t_utils	*utils);
int		check_if(const char *arg);
int		check_neg(t_list *stack_a);
int		my_atoi(const char *str, int *ret);

#endif
