/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:47:31 by minakim           #+#    #+#             */
/*   Updated: 2023/06/29 22:18:04 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"


// TODO: 만약에 이 함수를 만드는게 더 낫다면 새로 만들기
void	reverse_rotate(t_stack *stack)
{

}

/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_A
 */
void	rra(t_stack *stack_A)
{
	t_doubly *last_node;

	if (stack_A == NULL || stack_A->list.head == NULL \
		|| stack_A->list.head == stack_A->list.last)
		return;
	last_node = stack_A->list.last;
	stack_A->list.last = last_node->prev;
	stack_A->list.last->next = NULL;
	last_node->next = stack_A->list.head;
	stack_A->list.head->prev = last_node;
	last_node->prev = NULL;
	stack_A->list.head = last_node;
	write(1, "rra\n", 5);
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
		|| stack_B->list.head == stack_B->list.last)
		return;
	last_node = stack_B->list.last;
	stack_B->list.last = last_node->prev;
	stack_B->list.last->next = NULL;
	last_node->next = stack_B->list.head;
	stack_B->list.head->prev = last_node;
	last_node->prev = NULL;
	stack_B->list.head = last_node;
	write(1, "rrb\n", 5);
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
	write(1, "rrr\n", 5);
}

