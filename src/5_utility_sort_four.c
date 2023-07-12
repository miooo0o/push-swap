/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:39:49 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 18:07:56 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 *
 * @param stack
 */
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

/**
 *
 * @param stack
 * @return
 */
int 	navigate_min(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		node = stack->list.head;
		result = (int)(intptr_t) node->data;
		while (node != NULL)
		{
			if (result > (int)(intptr_t)(node->data))
				result = (int)(intptr_t) node->data;
			node = node->next;
		}
		return (result);
	}
}

/**
 *
 * @param stack
 * @return
 */
int 	navigate_max(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		node = stack->list.last;
		result = (int)(intptr_t) node->data;
		while (node != NULL)
		{
			if (result < (int)(intptr_t) node->data)
				result = (int)(intptr_t) node->data;
			node = node->prev;
		}
		return (result);
	}
}

/**
 *
 * @param stack_A
 * @return
 */
int	navigate_sec_min(t_stack *stack_A)
{
	int min;
	int	sec_min;
	int	value;
	t_doubly *node;

	node = stack_A->list.head;
	min = navigate_min(stack_A);
	if (min < 0)
		ft_error_lstfree(stack_A, NULL);
	sec_min = MAX;
	while (node != NULL)
	{
		value = (int)(intptr_t)node->data;
		if (value != min && value < sec_min)
			sec_min = value;
		node = node->next;
	}
	return (sec_min);
}
