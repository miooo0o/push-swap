/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by minakim           #+#    #+#             */
/*   Updated: 2023/07/01 16:32:02 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 * @brief rotate b: Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rotate(t_stack *stack)
{
	t_doubly *head_node;
	t_doubly *next_of_head_node;

	if (stack == NULL || stack->list.head == NULL \
		|| stack->list.last == NULL \
		|| stack->list.head == stack->list.last)
		return ;
	head_node = stack->list.head;
	next_of_head_node = head_node->next;
	next_of_head_node->prev = NULL;
	stack->list.head = next_of_head_node;
	head_node->prev = stack->list.last;
	head_node->next = NULL;
	stack->list.last->next = head_node;
	stack->list.last = head_node;
	stack->list.head = next_of_head_node;
}

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_A)
{
	rotate(stack_A);
	ft_printf("ra\n");
}

/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_B)
{
	rotate(stack_B);
	ft_printf("rb\n");
}

/**
 * @brief ra and rb at the same time
 */
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
	ft_printf("rr\n");
}
