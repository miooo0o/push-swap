/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/09 15:13:50 by minakim          ###   ########.fr       */
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
		if ((int)(intptr_t) stack_B->list.head->data < target->min)
			rb(stack_B);
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


// TODO : stack A[bot]에 임시로 보관하는 로직 필요
// TODO : 이후 group *target update -> loop till end.
void	take_next_node(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int remain;
	t_doubly *basis;
	t_num dest;
	int result;

	while (target->range - count_remaining_nodes(stack_A, target) != target->range)
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
		else
		{
			dest.data = (int)(intptr_t)basis->data - 1;
			result = opt_by_step(stack_B, &dest);
			if (result == -1)
				ft_error_basic("error");
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
	ft_printf("second sort finish\n");
}

void	sort_in_range(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int i;

	i = 0;
	while (++i < target->range)
	{
		if ((int)(intptr_t)stack_B->list.head->data + 1 == (int)(intptr_t)stack_A->list.head->data)
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
	ft_printf("first sort finish\n");
	take_next_node(stack_A, stack_B, target);
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
	ft_printf("divide finish\n");
	sort_in_range(&stack_A, &stack_B, &target);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}

// 43 85 40 62 36 27 15 33 82 67 47 92 64 59 14 74 94 77 16 45 58 29 34 90 78 83 88 68 70 87 93 50 65 9 24 25 86 100 30 22 4 2 1 8 5 56 44 19 21 18 84 61 35 49 26 38 54 95 48 53 46 60 57 91 3 89 96 52 80 73 66 41 75 97 55 42 98 7 13 63 12 69 17 37 32 10 28 51 6 20 76 79 11 23 31 81 71 39 99 72