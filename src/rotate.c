/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by minakim           #+#    #+#             */
/*   Updated: 2023/06/20 14:47:53 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_A)
{
	t_doubly *head_node;

	if (stack_A == NULL || stack_A->list.head == NULL \
		|| stack_A->list.last == NULL \
		|| stack_A->list.head == stack_A->list.last)
		return ;
	head_node = stack_A->list.head;
	stack_A->list.head = head_node->next;
	stack_A->list.head->prev = NULL;
	head_node->prev = stack_A->list.last;
	stack_A->list.last->next = head_node;
	head_node->next = NULL;
	stack_A->list.last = head_node;
}


/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_B)
{
	t_doubly *head_node;

	if (stack_B == NULL || stack_B->list.head == NULL \
		|| stack_B->list.last == NULL \
		|| stack_B->list.head == stack_B->list.last)
		return ;
	head_node = stack_B->list.head;
	stack_B->list.head = head_node->next;
	stack_B->list.head->prev = NULL;
	head_node->prev = stack_B->list.last;
	stack_B->list.last->next = head_node;
	head_node->next = NULL;
	stack_B->list.last = head_node;
}

/**
 * @brief ra and rb at the same time
 */
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
}
