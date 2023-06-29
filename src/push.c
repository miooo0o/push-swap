/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:44:13 by minakim           #+#    #+#             */
/*   Updated: 2023/06/29 22:23:17 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"


// TODO: print 'pa, pb...'
// TODO: finish usage
/**
 * @param target_stack : target stack which hold total size of stack.
 * @param update : update total size value in target stack.
 * but if update == 0, reset total size as 0.
 */
void	update_stack_size(t_stack *target_stack, int update)
{
	if (update == 0)
		target_stack->total_size = 0;
	else
		target_stack->total_size += update;
}

/**
 * @brief taken 스택의 해드 노드를 put 스택의 해드 노드로 바꾸는 어쩌구
 * @param taken
 * @param put
 * @note "스택의 해드 노드"여야만 어쩌구
 */
void	dbl_put_top(t_stack **taken, t_stack **put)
{
	t_doubly *node;

	node = dbl_newnode((*taken)->list.head->data);
	dbl_add_front(&(*put)->list, &node);
	dbl_del(&(*taken)->list, (*taken)->list.head);
}

/**
 * @brief pa (push a): Take the first element at the top of b and put it
 * at the top of a.
 * @param
 * @param
 */
void	pa(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly *node;
	if (stack_B->list.head == NULL && stack_B->list.last == NULL)
		ft_error_basic("nothing in the stack");
	if (stack_A->list.head == NULL && stack_A->total_size == 0)
	{
		node = dbl_newnode((void *)(intptr_t )stack_B->list.head->data);
		stack_A->list.head = node;
		stack_A->list.last = NULL;
		dbl_del(&(stack_B->list), stack_B->list.head);
	}
	else
		dbl_put_top(&stack_B, &stack_A);
	update_stack_size(stack_A, +1);
	update_stack_size(stack_B, -1);
	ft_printf("pa\n");
}

/**
 * @brief pb (push b): Take the first element at the top of a and put it
 * at the top of b.
 * @param
 * @param
 */
void	pb(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly *node;
	if (stack_A->list.head == NULL && stack_A->list.last == NULL)
		ft_error_basic("nothing in the stack");
	if (stack_B->list.head == NULL)
	{
		node = dbl_newnode((void *)(intptr_t )stack_A->list.head->data);
		stack_B->list.head = node;
		stack_B->list.last = NULL;
		dbl_del(&(stack_A->list), stack_A->list.head);
	}
	else
		dbl_put_top(&stack_A, &stack_B);
	update_stack_size(stack_A, -1);
	update_stack_size(stack_B, +1);
	ft_printf("pb\n");
}