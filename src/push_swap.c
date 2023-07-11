/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/11 19:31:51 by minakim          ###   ########.fr       */
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

void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int size;
	t_doubly *node;
	int range;

	if (ft_issorted(stack_A))
		return ;
	printf("after sort in divide stack by ratio\n");
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

void	take_next_node(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int remain;
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
			if (result == -1){
				print_all_stack(stack_A, stack_B);
				ft_error_lstfree(stack_A, stack_B);
			}
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

void	sort_in_range(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int i;

	i = 0;
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

void	next_target_group(t_stack *stack, t_group *target)
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

 void	sort_loop(t_stack *stack_A, t_stack *stack_B, t_group *target)
 {

	int group_range;
	int i = 0;

	group_range = target->name;
	if (ft_issorted(stack_A))
	{
		push_swap_lstfree(stack_A, NULL);
		return ;
	}
	while (group_range > 0 /* && is_sorted(stack_A) != 1 */)
	{
		group_range = target->name;
		sort_in_range(stack_A, stack_B, target);
		next_target_group(stack_B, target);
	}
	if (!check_sorted(stack_A) && stack_B->list.head == NULL)
	{
		while (!check_sorted(stack_A))
			rra(stack_A);
	}
	push_swap_lstfree(stack_A, stack_B);
 }

void	sort_by_hard_coding(t_stack *stack_A, t_stack *stack_B)
{
	if (stack_A->stack_size == 2)
		sort_two(stack_A);
	else if (stack_A->stack_size == 3)
		sort_three(stack_A);
	else if (stack_A->stack_size == 4)
		sort_four(stack_A, stack_B);
	else if (stack_A->stack_size == 5)
		sort_five(stack_A, stack_B);
	else
		return ;
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
	if (check_sorted(&stack_A) && stack_B.list.head == NULL)
	{
		dbl_listfree(&(stack_A.list));
		exit(1);
	}
	if (stack_A.stack_size < 6)
	{
		sort_by_hard_coding(&stack_A, &stack_B);
		push_swap_lstfree(&stack_A, &stack_B);
	}
	else
	{
		target.base_range = set_range(stack_A.stack_size);
		divide_stack_by_ratio(&stack_A, &stack_B, &target);
		sort_loop(&stack_A, &stack_B, &target);
	}
}
