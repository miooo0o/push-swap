/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:04:37 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 15:39:37 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

int	dbl_del(t_dlst *list, t_doubly *node_to_delete)
{
	if (list == NULL || node_to_delete == NULL)
		return (0);
	if (list->head == node_to_delete)
	{
		list->head = node_to_delete->next;
		if (list->head != NULL)
			list->head->prev = NULL;
	}
	if (list->last == node_to_delete)
	{
		list->last = node_to_delete->prev;
		if (list->last != NULL)
			list->last->next = NULL;
	}
	if (node_to_delete->next != NULL)
		node_to_delete->next->prev = node_to_delete->prev;
	if (node_to_delete->prev != NULL)
		node_to_delete->prev->next = node_to_delete->next;
	node_to_delete->prev = NULL;
	node_to_delete->next = NULL;
	free(node_to_delete);
	return (1);
}
