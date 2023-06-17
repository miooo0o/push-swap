/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:24:26 by minakim           #+#    #+#             */
/*   Updated: 2023/06/15 13:24:26 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi■■■■■ <mi■■■■■@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:04:37 by minakim           #+#    #+#             */
/*   Updated: 2023/06/15 12:56:56 by mi■■■■■          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_del(t_lst *list, t_doubly *node_to_delete)
{
	if (list == NULL || node_to_delete == NULL)
		assert(!"Error: empty node input");
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
}