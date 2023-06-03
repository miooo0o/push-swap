/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 20:44:30 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

int dbl_add_back(t_lst *list, t_doubly *new_node)
{
	if (list == NULL || new_node == NULL)
		return (-1);
	if (list->head == NULL)
	{
		new_node->prev = NULL;
		list->head = new_node;
		list->last = new_node;
	}
	else
	{
		list->last->next = new_node;
		new_node->prev = list->last;
		list->last = new_node;
	}
	return (0);
}

/*
int dbl_add_back(t_doubly **node, t_doubly *new_node)
{
	t_doubly *temp;

	if (node == NULL || new_node == NULL)
		return (-1);
	if (*node == NULL)
	{
		new_node->prev = NULL;
		*node = new_node;
	}
	else
	{
		temp = dbl_move_last((*node));
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (0);
}*/