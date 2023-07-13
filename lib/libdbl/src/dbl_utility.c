/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:53:50 by minakim           #+#    #+#             */
/*   Updated: 2023/07/13 20:14:21 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

// TODO: 아직 에러 핸들링이 완료 되지 않음. 에러시 메세지만 출력되고 free하지 않는 상태.

/*
 * dbl_isfront - Checks if a given node is the front (first) node in a doubly
 * linked list.
 * @node: The node to check.
 *
 * Return: 1 if the node is the front node, 0 otherwise.
 **/
int	dbl_isfront(t_doubly *node)
{
	if (node->prev == NULL)
		return (1);
	return (0);
}

/*
 * dbl_islast - Checks if a given node is the last node in a doubly linked list.
 * @node: The node to check.
 *
 * Return: 1 if the node is the last node, 0 otherwise.
 **/
int	dbl_islast(t_doubly *node)
{
	if (node->next == NULL)
		return (1);
	return (0);
}

/*
 * dbl_isadjac - Checks if two given nodes are adjacent to each other in a doubly
 * linked list.
 * @node_A: The first node to check.
 * @node_B: The second node to check.
 *
 * Return: 1 if the nodes are adjacent, 0 otherwise.
 **/
int	dbl_isadjac(t_doubly *node_A, t_doubly *node_B)
{
	if (node_A->next == node_B || node_B->next == node_A)
		return (1);
	return (0);
}
