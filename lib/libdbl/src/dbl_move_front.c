/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_move_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:24:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 20:52:26 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/libdbl.h"
#include "libdbl.h"

t_doubly    *dbl_move_front(t_lst *list)
{
	if (list == NULL)
		return (NULL);
	return (list->head);
}

/*
t_doubly    *dbl_move_front(t_doubly *lst)
{
	t_doubly 	*temp;

	temp = lst;
	while (temp != NULL && temp->prev != NULL)
		temp = temp->prev;
	return (temp);
}*/