/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:39:49 by minakim           #+#    #+#             */
/*   Updated: 2023/07/09 13:59:32 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 *
 * @param stack_A
 * @param stack_B
 */
void	sort_four(t_stack *stack_A, t_stack *stack_B)
{
	if (ft_issorted(stack_A))
		return ;
	find_min_and_bring_top(stack_A);
	if (!ft_issorted(stack_A))
	{
		pb(stack_A, stack_B);
		sort_three(stack_A);
		pa(stack_A, stack_B);
	}
}

void	find_step_from_bot(t_stack *stack, int target, int *step)
{
	t_doubly *node;
	*step = 0;
	node = stack->list.last;
	while (node != NULL)
	{
		(*step)++;
		if ((int)(intptr_t)node->data == target)
			break;
		node = node->prev;
	}
	if (node == NULL || (int)(intptr_t)node->data != target)
		(*step) = -1;
}

void	find_step_from_top(t_stack *stack, int target, int *step)
{
	t_doubly *node;

	node = stack->list.head;
	*step = 0;
	while (node != NULL)
	{
		(*step)++;
		if ((int)(intptr_t)node->data == target)
			break;
		node = node->next;
	}
	if (node == NULL || (int)(intptr_t)node->data != target)
		(*step) = -1;
}

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

void	find_min_and_bring_top(t_stack *stack)
{
	t_num min;
	t_doubly *node;

	min.data = navigate_min(stack);
	node = stack->list.head;
	if (opt_by_step(stack, &min) == RUN_TOP)
	{
		while ((int)(intptr_t)node->data != min.data)
		{
			ra(stack);
			node = stack->list.head;
		}
	}
	else
	{
		while ((int)(intptr_t)node->data != min.data)
		{
			rra(stack);
			node = stack->list.head;
		}
	}
}