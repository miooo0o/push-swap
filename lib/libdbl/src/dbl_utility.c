/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:53:50 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 15:57:11 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

int	dbl_isfront(t_doubly *node)
{
	if (node->prev == NULL)
		return (1);
	return (0);
}

int	dbl_islast(t_doubly *node)
{
	if (node->next == NULL)
		return (1);
	return (0);
}

int dbl_isadjac(t_doubly *node_A, t_doubly *node_B)
{
	if (node_A->next == node_B || node_B->next == node_A)
		return (1);
	return (0);
}