/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_listfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:47:33 by minakim           #+#    #+#             */
/*   Updated: 2023/06/09 09:56:50 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_listfree(t_lst *list)
{
	t_doubly *current;
	t_doubly *next_node;

	current = list->head;
	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;
	}
}