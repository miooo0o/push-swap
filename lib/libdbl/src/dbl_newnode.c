/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:10:36 by minakim           #+#    #+#             */
/*   Updated: 2023/07/01 16:51:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libdbl.h"
#include "libdbl.h"

t_doubly    *dbl_newnode(void *content)
{
	t_doubly *new_node;

	new_node = (t_doubly *)malloc(sizeof (t_doubly));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}