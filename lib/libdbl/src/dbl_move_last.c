/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:55:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 20:53:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

t_doubly	*dbl_move_last(t_lst *list)
{
	if (list == NULL)
		return NULL;
	return (list->last);
}

/*
t_doubly    *dbl_move_last(t_doubly *lst)
{
	t_doubly 	*temp;

	temp = lst;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	return (temp);
}*/