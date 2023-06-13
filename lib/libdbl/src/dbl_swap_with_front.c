/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_with_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:09:33 by minakim           #+#    #+#             */
/*   Updated: 2023/06/13 15:31:16 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/*
 * Swaps the front node with the next node in a doubly linked list.
 *
 * @front_node_ptr: Pointer to the pointer of the front node.
 * @next_node_ptr: Pointer to the pointer of the next node.
 * @list: Pointer to the doubly linked list.
 *
 * Swaps the positions of the front node and the next node in the list @list.
 * Updates the necessary pointers to maintain the correct connections.
 * Assumes that @front_node_ptr and @next_node_ptr are valid pointers and
 * that the list is not empty.
 */


void dbl_swap_front_and_next(t_doubly **front_node_ptr, t_doubly **next_node_ptr, t_lst *list)
{
	t_doubly *front_node;
	t_doubly *next_node;
	t_doubly *next_next_node;

	front_node = *front_node_ptr;
	if (front_node_ptr == NULL || next_node_ptr == NULL || list == NULL \
	|| (*front_node_ptr)->next != (*next_node_ptr) || front_node->prev != NULL)
		assert(!"Error: empty node input");
	next_node = (*front_node_ptr)->next;
	next_next_node = next_node->next;
	next_node->prev = front_node->prev;
	next_node->next = front_node;
	front_node->prev = next_node;
	front_node->next = next_next_node;
	if (next_next_node != NULL)
		next_next_node->prev = front_node;
	else
		list->last = front_node;
	if (list->head == *front_node_ptr)
		list->head = next_node;
	front_node_ptr = &front_node;
	next_node_ptr = &next_node;
	(*front_node_ptr)->next = next_next_node;
}

/*
 * Swaps the front node with another node in a doubly linked list.
 *
 * @front_node_ptr: Pointer to the pointer of the front node.
 * @other_node_ptr: Pointer to the pointer of the other node.
 * @list: Pointer to the doubly linked list.
 *
 * Swaps the positions of the front node and the other node in the list @list.
 * Updates the necessary pointers to maintain the correct connections.
 * Assumes that @front_node_ptr and @other_node_ptr are valid pointers
 * and that the list is not empty.
 */
void	dbl_swap_front_and_other(t_doubly **front_node_ptr, t_doubly **other_node_ptr, t_lst *list)
{
	t_doubly *next_of_front;
	t_doubly *front_node;
	t_doubly *other_node;

	front_node = *front_node_ptr;
	other_node = *other_node_ptr;
	if (front_node_ptr == NULL || other_node_ptr == NULL || list == NULL)
		assert(!"Error: empty node input");
	next_of_front = front_node->next;
	front_node->next = other_node->next;
	if (other_node->next != NULL)
		other_node->next->prev = front_node;
	front_node->prev = other_node->prev;
	if (other_node->prev != NULL)
		other_node->prev->next = front_node;
	other_node->next = next_of_front;
	if (next_of_front != NULL)
		next_of_front->prev = other_node;
	other_node->prev = NULL;
	if (list->head == *front_node_ptr)
		list->head = other_node;
	front_node_ptr = &front_node;
	other_node_ptr = &other_node;
}

t_doubly *set_front_node(t_doubly *node_A, t_doubly *node_B)
{
	if (dbl_isfront(node_A))
		return (node_A);
	if (dbl_isfront(node_B))
		return (node_B);
	return (NULL);
}

t_doubly *set_other_node_front(t_doubly *node_A, t_doubly *node_B)
{
	if (dbl_isfront(node_A))
		return (node_B);
	if (dbl_isfront(node_B))
		return (node_A);
	return (NULL);
}

/*
 * Swaps two nodes with the front node in a doubly linked list.
 *
 * @node_A: Pointer to the first node to swap.
 * @node_B: Pointer to the second node to swap.
 * @list: Pointer to the doubly linked list.
 *
 * This function swaps the positions of the nodes @node_A and @node_B
 * with the front node in the doubly linked list @list.
 * It determines the front node and the other node between @node_A and @node_B.
 * Depending on adjacency, it calls the appropriate swapping function
 * and updates the node pointers.
 *
 * Note: Assumes @node_A and @node_B are valid pointers and that the list is not empty.
 */

void	dbl_swap_with_front(t_doubly **node_A, t_doubly **node_B, t_lst *list)
{
	t_doubly *front_node;
	t_doubly *other_node;

	if (node_A == NULL || node_B == NULL || list == NULL)
		assert(!"Error: empty node input");
	front_node = set_front_node(*node_A, *node_B);
	other_node = set_other_node_front(*node_A, *node_B);
	if (other_node->prev == front_node)
		dbl_swap_front_and_next(&front_node, &other_node, list);
	else
		dbl_swap_front_and_other(&front_node, &other_node, list);
	if (front_node == *node_A)
	{
		node_A = &other_node;
		node_B = &front_node;
	}
	else if (front_node == *node_B)
	{
		node_A = &front_node;
		node_B = &other_node;
	}
	else
		assert(!"Error: wrong node inited");
}

