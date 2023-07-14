/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_group_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:31:30 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 13:31:36 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

void	next_target_group(t_group *target)
{
	if (target->name <= target->group_last)
	{
		target->range = target->base_range;
		target->max = target->min - 1;
		target->min = target->max - 11;
		target->name -= 1;
	}
	if (target->name < 1)
		return ;
}

int	count_remaining_nodes(t_stack *stack_A, t_group *target)
{
	int			count;
	t_doubly	*node;

	count = 0;
	node = stack_A->list.last;
	while (node != NULL && (int)(intptr_t)node->data != target->max)
		node = node->prev;
	while (node != NULL && (int)(intptr_t)node->data >= target->min)
	{
		count++;
		node = node->prev;
	}
	return (target->range - count);
}

void	pa_ra(t_stack *stack_a, t_stack *stack_b)
{
	pa(stack_a, stack_b);
	ra(stack_b);
}

void	rrb_pa(t_stack *stack_a, t_stack *stack_b)
{
	rrb(stack_b);
	pa(stack_a, stack_b);
}
