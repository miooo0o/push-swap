/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 13:04:07 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_add_back(t_lst *list, t_doubly **new_node)
{
	if (list == NULL || *new_node == NULL)
		assert(!"Error: empty node input");
	if (list->head == NULL)
	{
		(*new_node)->prev = NULL;
		list->head = *new_node;
		list->last = *new_node;
	}
	else
	{
		list->last->next = *new_node;
		(*new_node)->prev = list->last;
		list->last = *new_node;
	}
}