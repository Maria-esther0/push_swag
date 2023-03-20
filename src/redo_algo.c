/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redo_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillarr <mvillarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:49:11 by mvillarr          #+#    #+#             */
/*   Updated: 2023/03/20 20:44:08 by mvillarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// A simple C program for
// traversal of a linked list

struct Node {
	int data;
	struct Node* next;
};

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* n)
{
	while (n != NULL) {
		printf(" %d ", n->data);
		n = n->next;
	}
}

// Driver's code
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;

	third->data = 3; // assign data to third node
	third->next = NULL;

	// Function call
	printList(head);

	return 0;
}

