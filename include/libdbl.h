/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdbl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:11:50 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 21:49:57 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDBL_H
#define LIBDBL_H

# include "libft.h"

/*
 * This struct, 't_doubly', represents a node in a doubly linked list.
 * @data : (void) to store the data of the node.
 * @prev : pointer points to the previous node in the list.
 * @next : pointer points to the subsequent node.
 **/
typedef struct		s_doubly{
	void            *data;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

/*
 * This struct contains pointers to the first and the last nodes of the list.
 * @head : first node in the list.
 * @last : last node in the list.
 **/
typedef struct 		s_lst{
	t_doubly *head;
	t_doubly *last;
}					t_lst;


int			dbl_add_front(t_lst *list, t_doubly *new_node);
int			dbl_add_back(t_lst *list, t_doubly *new_node);
void		dbl_del(t_lst *list, t_doubly *node_to_delete);
int			dbl_listsize(t_doubly *node);
t_doubly    *dbl_move_front(t_lst *list);
t_doubly	*dbl_move_last(t_lst *list);
t_doubly    *dbl_newnode(void *content);

int			dbl_isfront(t_doubly *node);
int			dbl_islast(t_doubly *node);
int			dbl_isadjac(t_doubly *node_A, t_doubly *node_B);

/* swap : front node and other node */
void		dbl_swap_with_front(t_doubly **node_A, t_doubly **node_B, \
t_lst *list);
void		dbl_swap_front_and_other(t_doubly *front_node, t_doubly *other_node, \
t_lst *list);
void		dbl_swap_front_and_next(t_doubly *front_node, t_doubly *next_node, \t_lst *list);
/* swap : adjacent nodes */
void		dbl_swap_adjac(t_doubly *node_A, t_doubly *node_B)

#endif