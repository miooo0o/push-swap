/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_front_and_last.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:46:52 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 12:51:56 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/**
 * @brief Swaps the front node with the last node in a doubly linked list.
 * Swaps the positions of the front node and the last node in the list 'list'.
 * Updates the necessary pointers to maintain the correct connections.
 * @param front_ptr Pointer to the pointer of the front node.
 * @param last_ptr Pointer to the pointer of the next node.
 * @param list Pointer to the doubly linked list.
 * @note Assumes that 'front_ptr' and 'last_ptr' are valid pointers and
 * that the list is not empty.
 */
void	dbl_swap_front_and_last(t_doubly **front_ptr, t_doubly **last_ptr, t_lst *list)
{
	t_doubly *head_node;
	t_doubly *last_node;

	head_node = *front_ptr;
	last_node = *last_ptr;
	head_node->next->prev = last_node;
	last_node->prev->next = head_node;
	head_node->prev = last_node->prev;
	last_node->next = head_node->next;
	head_node->next = NULL;
	last_node->prev = NULL;
	list->last = head_node;
	list->head = last_node;
	front_ptr = &head_node;
	last_ptr = &last_node;
}
