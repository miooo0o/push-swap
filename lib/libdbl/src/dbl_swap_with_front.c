/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_with_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:09:33 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 21:35:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_swap_front_and_next(t_doubly *front_node, t_doubly *next_node, \
t_lst *list)
{
	front_node->next = next_node->next;
	if (next_node->next != NULL)
		next_node->next->prev = front_node;
	next_node->next = front_node;
	next_node->prev = front_node->prev;
	front_node->prev = next_node;
	if (list->head == front_node)
		list->head = next_node;
}

void	dbl_swap_front_and_other(t_doubly *front_node, t_doubly *other_node, \
t_lst *list)
{
	t_doubly *next_of_front;

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

	if (list->head == front_node)
		list->head = other_node;
}

void	dbl_swap_with_front(t_doubly **node_A, t_doubly **node_B, t_lst *list)
{
	t_doubly *front_node;
	t_doubly *other_node;

	if (dbl_isfront(*node_A))
	{
		front_node = *node_A;
		other_node = *node_B;
	}
	else
	{
		front_node = *node_B;
		other_node = *node_A;
	}
	if (other_node->prev == front_node)
		dbl_swap_front_and_next(front_node, other_node, list);
	else
		dbl_swap_front_and_other(front_node, other_node, list);
}

