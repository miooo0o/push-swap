/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_condition_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:37:22 by minakim           #+#    #+#             */
/*   Updated: 2023/07/17 14:37:25 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

int	target_is_b_head(t_stack *stack_A, t_stack *stack_B)
{
	if ((int)(intptr_t)stack_A->list.head->data - 1 == \
	(int)(intptr_t)stack_B->list.head->data)
		return (1);
	return (0);
}

int	target_is_b_bot(t_stack *stack_A, t_stack *stack_B)
{
	if ((int)(intptr_t)stack_A->list.head->data - 1 == \
		(int)(intptr_t)stack_B->list.last->data)
		return (1);
	return (0);
}

int	target_is_a_bot(t_stack *stack_A, t_stack *stack_B)
{
	if ((int)(intptr_t)stack_A->list.head->data - 1 \
		== (int)(intptr_t)stack_A->list.last->data)
		return (1);
	return (0);
}

int	push_to_a_bot(t_stack *stack_A, t_stack *stack_B)
{
	if ((int)(intptr_t)stack_A->list.last->data == stack_A->max_total
		|| ((int)(intptr_t)stack_A->list.last->data != stack_A->max_total
			&& (int)(intptr_t)stack_A->list.last->data < \
				(int)(intptr_t)stack_B->list.head->data))
		return (1);
	return (0);
}
