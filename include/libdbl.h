/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdbl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:11:50 by minakim           #+#    #+#             */
/*   Updated: 2023/06/03 15:12:33 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDBL_H
#define LIBDBL_H

# include "libft.h"

typedef struct		s_doubly{
	void            *data;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

int dbl_add_back(t_doubly **node, t_doubly *new_node);
int dbl_add_front(t_doubly **head_node,t_doubly *new_node);
int	dbl_listsize(t_doubly *node);
t_doubly    *dbl_move_last(t_doubly *lst);
t_doubly    *dbl_newnode(t_doubly **prev_node, void *content);

#endif