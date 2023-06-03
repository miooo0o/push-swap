/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap_adjac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:41:01 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 21:46:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

void	dbl_swap_adjac(t_doubly *node_A, t_doubly *node_B)
{
	t_doubly *next_of_node_A;
	t_doubly *prev_of_node_A;

	next_of_node_A = node_A->next;
	prev_of_node_A = node_A->prev;
	node_A->next = node_B->next;
	if (node_B->next != NULL)
		node_B->next->prev = node_A;
	node_A->prev = node_B->prev;
	if (node_B->prev != NULL)
		node_B->prev->next = node_A;
	node_B->next = next_of_node_A;
	if (next_of_node_A != NULL)
		next_of_node_A->prev = node_B;
	node_B->prev = prev_of_node_A;
}