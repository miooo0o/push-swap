/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_hard_coding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:31:38 by minakim           #+#    #+#             */
/*   Updated: 2023/07/03 21:43:31 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 * @brief
 * @param stack
 */
void	sort_two(t_stack *stack)
{
	if (stack->list.head->data > stack->list.head->next->data)
		sa(stack);
}

/**
 * @brief
 * @param stack
 */
void	sort_three(t_stack *stack)
{

	if (ft_issorted(stack))
		return ;
	if ((intptr_t)(stack->list.head->data) > (intptr_t)(stack)->list.head->next->next->data
		&& ((intptr_t)(stack)->list.head->data > (intptr_t)(stack)->list.head->next->data))
		ra(stack);
	if ((intptr_t)(stack)->list.head->next->data > (intptr_t)(stack)->list.head->next->next->data)
		rra(stack);
	if ((intptr_t)(stack)->list.head->data > (intptr_t)(stack)->list.head->next->data)
		sa(stack);
}

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

int	navigate_sec_min(t_stack *stack_A)
{
	int min;
	int	sec_min;
	int	value;
	t_doubly *node;

	node = stack_A->list.head;
	min = navigate_min(stack_A);
	if (min < 0)
		ft_error_basic("error, [need free]");
	sec_min = 1024;
	while (node != NULL)
	{
		value = (int)(intptr_t)node->data;
		if (value != min && value < sec_min)
			sec_min = value;
		node = node->next;
	}
	return (sec_min);
}
