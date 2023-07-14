/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:49:52 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:49:52 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

void	sort_loop(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int group_range;

	group_range = target->name;
	if (ft_issorted(stack_A))
	{
		push_swap_lstfree(stack_A, NULL);
		return ;
	}
	while (group_range > 0)
	{
		group_range = target->name;
		sort_in_range(stack_A, stack_B, target);
		next_target_group(target);
	}
	if (!check_sorted(stack_A) && stack_B->list.head == NULL)
	{
		while (!check_sorted(stack_A))
			rra(stack_A);
	}
	push_swap_lstfree(stack_A, stack_B);
}

void	sort_in_range(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	while (stack_B->list.head != NULL && (int)(intptr_t) stack_B->list.head->data >= target->min && (int)(intptr_t) stack_B->list.head->data <= target->max)
	{
		if (stack_B->stack_size == 0)
			exit(1);
		else if ((int)(intptr_t)stack_B->list.head->data + 1 == (int)(intptr_t)stack_A->list.head->data)
			pa(stack_A, stack_B);
		else if ((int)(intptr_t)stack_A->list.last->data + 1 == (int)(intptr_t)stack_A->list.head->data)
			rra(stack_A);
		else if ((int)(intptr_t)stack_A->list.last->data == stack_A->max_total &&
				 (int)(intptr_t)stack_A->list.last->data < (int)(intptr_t)stack_B->list.head->data)
		{
			pa(stack_A, stack_B);
			ra(stack_A);
		}
		else if (stack_B->list.last != NULL && (int)(intptr_t)stack_A->list.head->data == (int)(intptr_t)stack_B->list.last->data + 1)
		{
			rrb(stack_B);
			pa(stack_A, stack_B);
		}
		else
			rb(stack_B);
	}
	take_next_node(stack_A, stack_B, target);
}

void	take_next_node(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	t_doubly *basis;
	t_num dest;
	int result;

	while (stack_B->list.head != NULL && target->range - count_remaining_nodes(stack_A, target) != target->range)
	{
		basis = stack_A->list.head;
		if ((int)(intptr_t)basis->data - 1 == (int)(intptr_t)stack_B->list.head->data)
			pa(stack_A, stack_B);
		else if ((int)(intptr_t)basis->data - 1 == (int)(intptr_t)stack_B->list.last->data)
		{
			rrb(stack_B);
			pa(stack_A, stack_B);
		}
		else if ((int)(intptr_t)basis->data - 1 == (int)(intptr_t)stack_A->list.last->data)
			rra(stack_A);
		else if ((int)(intptr_t)stack_A->list.last->data == stack_A->max_total
				 || ((int)(intptr_t)stack_A->list.last->data != stack_A->max_total
					 && (int)(intptr_t)stack_A->list.last->data < (int)(intptr_t)stack_B->list.head->data))
		{
			pa(stack_A, stack_B);
			ra(stack_A);
		}
		else
		{
			dest.data = (int)(intptr_t)basis->data - 1;
			result = opt_by_step(stack_B, &dest);
			if (result == -1)
				ft_error_lstfree(stack_A, stack_B);
			if (result == RUN_TOP)
			{
				while ((int)(intptr_t)stack_B->list.head->data != dest.data)
					rb(stack_B);
			}
			else
			{
				while ((int)(intptr_t) stack_B->list.head->data != dest.data)
					rrb(stack_B);
			}
		}
	}
}

int count_remaining_nodes(t_stack *stack_A, t_group *target)
{
	int count = 0;
	t_doubly *node = stack_A->list.last;


	while (node != NULL && (int)(intptr_t)node->data != target->max)
		node = node->prev;
	while (node != NULL && (int)(intptr_t)node->data >= target->min)
	{
		count++;
		node = node->prev;
	}
	return (target->range - count);
}