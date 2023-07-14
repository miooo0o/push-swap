/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 11:04:44 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

int	dbl_add_front(t_dlst *list, t_doubly **new_node)
{
	if (*new_node == NULL)
		return (0);
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
	return (1);
}