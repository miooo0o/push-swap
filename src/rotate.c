/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:46:29 by minakim           #+#    #+#             */
/*   Updated: 2023/06/27 22:30:44 by minakim          ###   ########.fr       */
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
	ft_printf("ra\n");
}

// rotate 에 문제가 있어 보입니다!

/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack)
{
	t_doubly *head_node;

	if (stack == NULL || stack->list.head == NULL \
		|| stack->list.last == NULL \
		|| stack->list.head == stack->list.last)
		return ;
	head_node = stack->list.head;
	stack->list.head = head_node->next;
	stack->list.head->prev = NULL;
	head_node->prev = stack->list.last;
	stack->list.last->next = head_node;
	head_node->next = NULL;
	stack->list.last = head_node;
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
