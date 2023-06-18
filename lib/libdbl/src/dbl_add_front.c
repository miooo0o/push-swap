/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 13:04:02 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_add_front(t_lst *list, t_doubly **new_node)
{
	if (*new_node == NULL)
		assert(!"Error: empty node input");
	if (list->head == NULL)
	{
		(*new_node)->prev = NULL;
		(*new_node)->next = NULL;
		list->head = *new_node;
		list->last = *new_node;
	}
	else
	{
		(*new_node)->next = list->head;
		list->head->prev = *new_node;
		(*new_node)->prev = NULL;
		list->head = *new_node;
	}
}