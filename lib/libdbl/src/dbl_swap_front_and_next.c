/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:06:59 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 15:40:09 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

int	dbl_swap_front_and_next(t_doubly **front_ptr, \
	t_doubly **next_ptr, t_dlst *list)
{
	t_doubly	*front_node;
	t_doubly	*next_node;
	t_doubly	*next_next_node;

	front_node = *front_ptr;
	if (front_ptr == NULL || next_ptr == NULL || list == NULL \
	|| (*front_ptr)->next != (*next_ptr) || front_node->prev != NULL)
		return (0);
	next_node = (*front_ptr)->next;
	next_next_node = next_node->next;
	next_node->prev = front_node->prev;
	next_node->next = front_node;
	front_node->prev = next_node;
	front_node->next = next_next_node;
	if (next_next_node != NULL)
		next_next_node->prev = front_node;
	else
		list->last = front_node;
	if (list->head == *front_ptr)
		list->head = next_node;
	front_ptr = &front_node;
	next_ptr = &next_node;
	(*front_ptr)->next = next_next_node;
	return (1);
}
