/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_by_ratio.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:50:29 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:51:49 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int size;

	if (ft_issorted(stack_A))
		return ;
	size = stack_A->stack_size;
	set_last_group(target, size);
	range_group_to_stack(stack_A, stack_B, target->base_range);
	while (stack_A->stack_size > 1)
	{
		if ((int)(intptr_t) stack_A->list.head->data == stack_A->max_total)
			ra(stack_A);
		pb(stack_A, stack_B);
		if ((int)(intptr_t) stack_B->list.head->data < target->min)
			rb(stack_B);
	}
	if (stack_A->list.head == NULL || (int)(intptr_t) stack_A->list.head->data != stack_A->max_total)
		push_till_get_max(stack_A, stack_B, target);
}

void	set_last_group(t_group *target, int size)
{
	int max;

	target->group_last = 0;
	target->max = size - 1;
	max = target->max;
	if (target->base_range == 0)
		return ;
	while (max - target->base_range >= 0)
	{
		max = max - target->base_range;
		target->group_last++;
	}
	if (max > 0)
		target->group_last++;
	target->min = (target->group_last - 1) * target->base_range;
	target->name = target->group_last;
	target->range = target->max - target->min + 1;
}

void	range_group_to_stack(t_stack *stack_A, t_stack *stack_B, int range)
{
	int	size;
	int i;
	int	temp;
	t_doubly *node;

	temp = range;
	while (range <= stack_A->max_total)
	{
		size = stack_A->stack_size;
		i = 0;
		while (++i < size)
		{
			node = stack_A->list.head;
			if ((int)(intptr_t)node->data < range)
			{
				pb(stack_A, stack_B);
				rb(stack_B);
			}
			else if ((int)(intptr_t)node->data >= (int)(range + temp) || (int)(intptr_t)node->data == stack_A->max_total)
				ra(stack_A);
			else
				pb(stack_A, stack_B);
		}
		range += temp * 2;
	}
}

void	push_till_get_max(t_stack *stack_A, t_stack *stack_B, t_group *group)
{
	int swap_trigger;
	int sec_max;
	int cnt;
	t_doubly *node;

	sec_max = stack_A->max_total - 1;
	swap_trigger = 0;
	cnt = 0;
	node = stack_A->list.head;
	while (++cnt < group->base_range)
	{
		if ((int)(intptr_t)node->data == sec_max)
		{
			pa(stack_A, stack_B);
			swap_trigger = 1;
		}
		else if ((int)(intptr_t)node->data == stack_A->max_total)
		{
			pa(stack_A, stack_B);
			if (swap_trigger == 1)
				sa(stack_A);
			break ;
		}
		else
			rb(stack_B);
	}

}

int	set_range(int len)
{
	int	val;
	int	range;
	double ratio;

	ratio = 0.01;
	val = 10;
	if (len > 100)
		val = 20;
	range = 0;
	if ((len / val) <= 1)
		return (1);
	while (range < (len / val))
	{
		range += (int)(len * ratio);
		ratio += 0.005;
	}
	return (range);
}