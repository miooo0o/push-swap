/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_step.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:06:39 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 18:06:52 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 *
 * @param stack
 * @param target
 * @param step
 */
void	find_step_from_bot(t_stack *stack, int target, int *step)
{
	t_doubly	*node;

	*step = 0;
	node = stack->list.last;
	while (node != NULL)
	{
		(*step)++;
		if ((int)(intptr_t)node->data == target)
			break ;
		node = node->prev;
	}
	if (node == NULL || (int)(intptr_t)node->data != target)
		(*step) = -1;
}

/**
 *
 * @param stack
 * @param target
 * @param step
 */
void	find_step_from_top(t_stack *stack, int target, int *step)
{
	t_doubly	*node;

	node = stack->list.head;
	*step = 0;
	while (node != NULL)
	{
		(*step)++;
		if ((int)(intptr_t)node->data == target)
			break ;
		node = node->next;
	}
	if (node == NULL || (int)(intptr_t)node->data != target)
		(*step) = -1;
}

/**
 *
 * @param stack
 * @param num
 * @return
 */
int	opt_by_step(t_stack *stack, t_num *num)
{
	find_step_from_top(stack, num->data, &num->step_top);
	find_step_from_bot(stack, num->data, &num->step_bot);
	if (num->step_bot == -1 && num->step_top == -1)
		return (-1);
	if (num->step_top < num->step_bot)
		return (RUN_TOP);
	else
		return (RUN_BOT);
}
