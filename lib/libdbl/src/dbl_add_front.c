/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/06/13 18:02:59 by minakim          ###   ########.fr       */
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

/*
int dbl_add_front(t_doubly **head_node,t_doubly *new_node) {
	if (head_node == NULL || new_node == NULL)
		return (-1);
	new_node->next = *head_node;
	if (*head_node != NULL)
		(*head_node)->prev = new_node;
	new_node->prev = NULL;
	*head_node = new_node;
	return (0);
}*/