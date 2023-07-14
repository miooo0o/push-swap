/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdbl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:11:50 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 11:18:35 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDBL_H
# define LIBDBL_H

/**
 * @brief 42 You should not use this library for your project.
 * the library below is used to test error handling.
 */
# include <assert.h>

/**
 * @brief This library depends on the following a library.
 */
# include "libft.h"


/**
 * This struct, 't_doubly', represents a node in a doubly linked list.
 * @param data : (void *) to store the data of the node.
 * @param prev : pointer points to the previous node in the list.
 * @param next : pointer points to the subsequent node.
 **/
typedef struct		s_doubly{
	void            *data;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

/**
 * @brief This struct contains pointers to the first and the last nodes
 * of the list.
 * @param head : first node in the list. head->prev should be set to NULL.
 * @param last : last node in the list. last->next should be set to NULL.
 **/
typedef struct 		s_dlst{
	t_doubly *head;
	t_doubly *last;
}					t_dlst;

/* List of functions used for the project */
int			dbl_swap_front_and_next(t_doubly **front_ptr, t_doubly **next_ptr, \
			t_dlst *list);
t_doubly    *dbl_newnode(void *content);
int			dbl_del(t_dlst *list, t_doubly *node_to_delete);
int			dbl_add_front(t_dlst *list, t_doubly **new_node);
int 		dbl_add_back(t_dlst *list, t_doubly **new_node);
void		dbl_listfree(t_dlst *list);
#endif