/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/07 17:36:46 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			else if ((int)(intptr_t)node->data >= (int)(range + temp))
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

void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int size;
	t_doubly *node;
	int range;

	size = stack_A->stack_size;
	set_last_group(target, size);
	range_group_to_stack(stack_A, stack_B, target->base_range);
	while (stack_A->stack_size > 1)
	{
		if ((int)(intptr_t) stack_A->list.head->data == stack_A->max_total)
			ra(stack_A);
		pb(stack_A, stack_B);
	}
	if (stack_A->list.head == NULL || (int)(intptr_t) stack_A->list.head->data != stack_A->max_total)
		push_till_get_max(stack_A, stack_B, target);
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

int	is_sorted_till_max(t_stack *stack)
{
	t_doubly *node;

	node = stack->list.head;
	while (node != NULL && node->next != NULL
		   && (int)(intptr_t) node->data != stack->max_total)
	{
		if ((int)(intptr_t)node->data + 1 == (int)(intptr_t)node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}



void	sort_in_range(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int i;
	int swap_trigger;

	swap_trigger = 0;
	i = 0;
	while (++i < target->range || stack_A->stack_size != target->range)
	{
		if ((int)(intptr_t)stack_B->list.head->data + 1 == (int)(intptr_t)stack_A->list.head->data)
			pa(stack_A, stack_B);
		else if ((int)(intptr_t)stack_B->list.head->data + 2 == (int)(intptr_t)stack_A->list.head->data)
		{
			pa(stack_A,stack_B);
			swap_trigger = 1;
		}
		else if (swap_trigger == 1 && ((int)(intptr_t)stack_A->list.head->data + 1 == (int)(intptr_t)stack_B->list.head->data))
		{
			pa(stack_A, stack_B);
			sa(stack_A);
			swap_trigger = 0;
		}
		else if ((int)(intptr_t)stack_A->list.last->data + 1 == (int)(intptr_t)stack_A->list.head->data)
			rra(stack_A);
		else if ((int)(intptr_t)stack_A->list.last->data == stack_A->max_total &&
				(int)(intptr_t)stack_A->list.last->data < (int)(intptr_t)stack_B->list.head->data)
		{
			pa(stack_A, stack_B);
			ra(stack_A);
		}
		else if ((int)(intptr_t)stack_B->list.last->data + 1 == (int)(intptr_t)stack_A->list.head->data)
		{
			rrb(stack_B);
			pa(stack_A, stack_B);
		}
		else
			rb(stack_B);
	}
}

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;
	t_group target;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_A, &stack_B);

	target.base_range = set_range(stack_A.stack_size);
	ft_printf("range %d\n", target.base_range);
	divide_stack_by_ratio(&stack_A, &stack_B, &target);
	sort_in_range(&stack_A, &stack_B, &target);
	ft_printf("target range %d\n", target.range);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}

// 54 95 69 41 64 18 66 82 28 56 91 4 9 81 90 13 24 59 7 38 29 0 63 47 23 77 93 94 10 3 21 19 52 20 72 78 80 1 33 86 50 87 27 26 32 43 84 45 49 11 68 14 89 31 74 48 99 34 8 40 12 16 75