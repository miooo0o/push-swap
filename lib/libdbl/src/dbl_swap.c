/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:09:54 by minakim           #+#    #+#             */
/*   Updated: 2023/06/05 21:49:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/*
 * The function checks the positions of node_A and node_B
 * and swaps them accordingly using the appropriate method.
 **/
void	dbl_swap(t_doubly **node_A, t_doubly **node_B, t_lst *list)
{
	if (*node_A == *node_B)
		assert(!"Error: node_A and node_B are same");
	else if (dbl_isfront(*node_A) || dbl_isfront(*node_B))
		dbl_swap_with_front(node_A, node_B, list);
	else if (dbl_isadjac(*node_A, *node_B))
		dbl_swap_adjac(*node_A, *node_B);
	else if (dbl_islast(*node_A) || dbl_islast(*node_B))
		dbl_swap_with_last(node_A, node_B, list);
	else
		assert(!"Error: can not swap.");
}