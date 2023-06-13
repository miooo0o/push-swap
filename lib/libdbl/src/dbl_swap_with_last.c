/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_with_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:54:48 by minakim           #+#    #+#             */
/*   Updated: 2023/06/13 15:01:49 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/*
 * Swaps the last node with a previous node in a doubly linked list.
 *
 * @last_node_ptr: Pointer to the last node pointer.
 * @prev_node_ptr: Pointer to the previous node pointer.
 * @list: Pointer to the doubly linked list.
 *
 * Swaps the position of the last node with the previous node in the list, updating pointers accordingly.
 **/
void	dbl_swap_last_and_prev(t_doubly **last_node_ptr, t_doubly **prev_node_ptr, t_lst *list)
{
	t_doubly *last_node;
	t_doubly *prev_node;

	if (*last_node_ptr == NULL || *prev_node_ptr == NULL || list == NULL)
		assert(!"Error: empty node input");
	last_node = *last_node_ptr;
	prev_node = *prev_node_ptr;
	if (prev_node->prev != NULL)
		prev_node->prev->next = last_node;
	else
		list->head = last_node;
	last_node->prev = prev_node->prev;
	prev_node->prev = last_node;
	prev_node->next = last_node->next;
	last_node->next = prev_node;
	if (list->last == *last_node_ptr)
		list->last = prev_node;
	else
		assert(!"Error: last_node is not the last node in the list");
	last_node_ptr = &last_node;
	prev_node_ptr = &prev_node;
}

/*
 * Swaps the last node with another node in a doubly linked list,
 * updating pointers accordingly.
 *
 * @last_node_ptr: Pointer to the last node pointer.
 * @other_node_ptr: Pointer to the other node pointer.
 * @list: Pointer to the doubly linked list.
 *
 * Note: Assumes valid pointers and a non-empty list.
 **/
void	dbl_swap_last_and_other(t_doubly **last_node_ptr, t_doubly **other_node_ptr, t_lst *list)
{
	t_doubly *last_node;
	t_doubly *other_node;
	t_doubly *prev_of_last;

	if (last_node_ptr == NULL || other_node_ptr == NULL || list == NULL)
		assert(!"Error: empty node input");
	last_node = *last_node_ptr;
	other_node = *other_node_ptr;
	prev_of_last = last_node->prev;
	last_node->prev = other_node->prev;
	if (other_node->prev != NULL)
		other_node->prev->next = last_node;
	last_node->next = other_node->next;
	if (other_node->next != NULL)
		other_node->next->prev = last_node;
	other_node->prev = prev_of_last;
	if (prev_of_last != NULL)
		prev_of_last->next = other_node;
	other_node->next = NULL;
	if (list->head == other_node)
		list->head = last_node;
	if (list->last == last_node)
		list->last = other_node;
	else
		assert(!"Error: last_node is not the last node in the list");
	last_node_ptr = &last_node;
	other_node_ptr = &other_node;
}

t_doubly *set_last_node(t_doubly *node_A, t_doubly *node_B)
{
	if (dbl_islast(node_A))
		return (node_A);
	if (dbl_islast(node_B))
		return (node_B);
	return (NULL);
}

t_doubly *set_other_node_last(t_doubly *node_A, t_doubly *node_B)
{
	if (dbl_islast(node_A))
		return (node_B);
	if (dbl_islast(node_B))
		return (node_A);
	return (NULL);
}

/*
 * Swaps two given nodes with the last node in a doubly linked list.
 *
 * @node_A: Pointer to the first node to swap.
 * @node_B: Pointer to the second node to swap.
 * @list: Pointer to the doubly linked list.
 *
 * Swaps the positions of @node_A and @node_B with the last node in the list @list.
 * Handles the case when the other node is adjacent to the last node or not.
 *
 * Note: Assumes @node_A and @node_B are valid pointers and that the list is not empty.
 */

void	dbl_swap_with_last(t_doubly **node_A, t_doubly **node_B, t_lst *list)
{
	t_doubly *last_node;
	t_doubly *other_node;

	if (node_A == NULL || node_B == NULL || list == NULL)
		assert(!"Error: empty node input");
	last_node = set_last_node(*node_A, *node_B);
	other_node = set_other_node_last(*node_A, *node_B);
	if (other_node->next == list->last)
		dbl_swap_last_and_prev(&last_node, &other_node, list);
	else
		dbl_swap_last_and_other(&last_node, &other_node, list);
	if (last_node == *node_A)
	{
		*node_A = other_node;
		*node_B = last_node;
	}
	else if (last_node == *node_B)
	{
		*node_A = last_node;
		*node_B = other_node;
	}
	else
		assert(!"Error: wrong node inited");
}