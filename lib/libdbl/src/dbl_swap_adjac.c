/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_adjac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:41:01 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 17:12:31 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/**
 * @brief Swaps adjact nodes in a doubly linked list.
 * the each node is not head and last node
 * @param
 * @note
 */
void	dbl_swap_adjac(t_doubly **node_A, t_doubly **node_B)
{
	t_doubly *first;
	t_doubly *second;

	if (*node_A == NULL || *node_B == NULL)
		assert(!"Error: node is empty.");
	if((*node_A)->next == *node_B)
	{
		first = *node_A;
		second = *node_B;
	} else if((*node_B)->next == *node_A)
	{
		first = *node_B;
		second = *node_A;
	} else
		assert(!"Error: node is not adjacent!");
	/* FIXME : 여기부터. temp를 만들어야 함. */
	if(first->prev != NULL)
		first->prev->next = second;
	second->prev = first->prev;
	first->next = second->next;
	if(second->next != NULL)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
}
