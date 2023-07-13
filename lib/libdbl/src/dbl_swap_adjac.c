/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_adjac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:41:01 by minakim           #+#    #+#             */
/*   Updated: 2023/07/13 20:13:36 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

t_doubly	*set_first(t_doubly *node_A, t_doubly *node_B)
{
	if (node_A->next == node_B)
		return (node_A);
	else if (node_B->next == node_A)
		return (node_B);
	else
		assert(!"Error: node is not adjacent!");
}

t_doubly	*set_second(t_doubly *node_A, t_doubly *node_B)
{
	if (node_A->next == node_B)
		return (node_B);
	else if (node_B->next == node_A)
		return (node_A);
	else
		assert(!"Error: node is not adjacent!");
}

/**
 * @brief Swaps adjact nodes in a doubly linked list.
 * the each node is not head and last node
 * @param
 * @note
 */
void	dbl_swap_adjac(t_doubly **node_A, t_doubly **node_B)
{
	t_doubly	*first;
	t_doubly	*second;

	if (*node_A == NULL || *node_B == NULL)
		assert(!"Error: node is empty.");
	first = set_first(*node_A, *node_B);
	second = set_second(*node_A, *node_B);
	if (first->prev != NULL)
		first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
}
