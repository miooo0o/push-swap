/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:47:31 by minakim           #+#    #+#             */
/*   Updated: 2023/07/11 19:40:25 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"



/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_A
 */
void	rra(t_stack *stack_A)
{
	t_doubly *last_node;

	if (stack_A == NULL || stack_A->list.head == NULL || stack_A->list.last == NULL\
		|| stack_A->list.head == stack_A->list.last)
		return;
	last_node = stack_A->list.last;
	stack_A->list.last = last_node->prev;
	stack_A->list.last->next = NULL;
	last_node->next = stack_A->list.head;
	stack_A->list.head->prev = last_node;
	last_node->prev = NULL;
	stack_A->list.head = last_node;
	ft_putendl_fd("rra", 1);
}

/**
 * @brief rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 * @param stack_B The last element becomes the first one.
 */
void	rrb(t_stack *stack_B)
{
	t_doubly *last_node;

	if (stack_B == NULL || stack_B->list.head == NULL \
		|| stack_B->list.head == stack_B->list.last || stack_B->list.last == NULL)
		return;
	last_node = stack_B->list.last;
	stack_B->list.last = last_node->prev;
	stack_B->list.last->next = NULL;
	last_node->next = stack_B->list.head;
	stack_B->list.head->prev = last_node;
	last_node->prev = NULL;
	stack_B->list.head = last_node;
	ft_putendl_fd("rrb", 1);
}


/**
 * @brief rrr : rra and rrb at the same time.
 * @param stack_A
 * @param stack_B
 */
void	rrr(t_stack *stack_A, t_stack *stack_B)
{
	rra(stack_A);
	rrb(stack_B);
	ft_putendl_fd("rrr", 1);
}

