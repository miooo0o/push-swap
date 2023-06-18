/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:09:54 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 11:59:17 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

/*
 * This function checks the positions of node_A and node_B
 * within the doubly linked list and swaps them
 * accordingly using the appropriate method.
 *
 * @node_A: A pointer to a pointer to the first node to be swapped.
 * @node_B: A pointer to a pointer to the second node to be swapped.
 * @list:   A pointer to the doubly linked list.
 *
 * Notes:
 *  - If @node_A and @node_B are the same, an error is thrown.
 *  - If either @node_A or @node_B is the front node,
 *  	the swap is performed with the front node.
 *  - If @node_A and @node_B are adjacent nodes, they are swapped directly.
 *  - If either @node_A or @node_B is the last node,
 *  	the swap is performed with the last node.
 *  - If none of the above conditions are met, an error is thrown.
 */
void	dbl_swap(t_doubly **node_A, t_doubly **node_B, t_lst *list)
{
	if (*node_A == *node_B)
		assert(!"Error: node_A and node_B are same");
	else if (dbl_isfront(*node_A)&& dbl_islast(*node_B))
		dbl_swap_front_and_last(node_A, node_B, list);
	else if (dbl_isfront(*node_B)&& dbl_islast(*node_A))
		dbl_swap_front_and_last(node_B, node_A, list);
	else if (dbl_isfront(*node_A) || dbl_isfront(*node_B))
		dbl_swap_with_front(node_A, node_B, list);
	else if (dbl_islast(*node_A) || dbl_islast(*node_B))
		dbl_swap_with_last(node_A, node_B, list);
	else if (dbl_isadjac(*node_A, *node_B))
		dbl_swap_adjac(node_A, node_B);
	else
		assert(!"Error: can not swap.");
}