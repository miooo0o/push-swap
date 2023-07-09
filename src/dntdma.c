/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dntdma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:31:37 by minakim           #+#    #+#             */
/*   Updated: 2023/07/07 23:49:41 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	update_target_group(t_stack *stack, t_group *target)
{
	/* if, target group nums sorted complete */
	if (target->name != 0)
	{
		target->range = target->base_range;
		target->max = target->min - 1;
		target->min = target->max - target->range + 1;
		target->min = (int)((target->min + target->max - 1) * 0.5);
		target->name -= 1;
//		if (target->name == 0 /* and target group nums not sorted complete */)
		/* force_sort_end */
	}
}

void	set_last_group(t_group *target, int size, double ratio)
{
	int max;

	target->group_last = 0;
	target->base_range = (int)(size * ratio);
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

void	set_first_group(t_group *target, int size, double ratio)
{
	int max;

	target->group_last = 0;
	target->base_range = (int)(size * ratio);
	target->max = target->base_range - 1;
	max = size - 1;
	if (target->base_range == 0)
		return ;
	while (max - target->base_range >= 0)
	{
		max = max - target->base_range;
		target->group_last++;
	}
	if (max > 0)
		target->group_last++;
	target->min = 0;
	target->name = 1;
	target->range = target->max - target->min + 1;
}

void	next_target_group(t_stack *stack, t_group *target)
{
	/* if, target group nums sorted complete */
	if (target->name < target->group_last)
	{
		target->range = target->base_range;
		target->max = target->min - 1;
		target->min = target->max - target->range + 1;
		target->min = (int)((target->min + target->max - 1) * 0.5);
		target->name += 1;
	}
	else
		set_last_group(target, stack->max_total, 0.12);
}

int		check_range_push_complete(t_stack *stack, t_group *target)
{
	int count;
	t_doubly *node;

	count = target->range;
	node = stack->list.head;
	while (node != NULL && count > 0)
	{
		if (!(target->min >= (int)(intptr_t) node->data && target->max <= (int)(intptr_t) node->data))
			return (0);
		else
			count--;
		node = node->next;
	}
	if (count != 0)
		return (0);
	return (1);
}

void	push_target_group(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	t_group *next_target;

	next_target = target;
	next_target_group(stack_A, next_target);
	while (target->name != 0)
	{
		if (!(check_range_push_complete(stack_B, target)))
		{
			if ((int)(intptr_t) stack_A->list.head->data >= target->min
				&& (int)(intptr_t)stack_A->list.head->data <= target->max)
			{
				pb(stack_A, stack_B);
				rb(stack_B);
			}
			else if (((int)(intptr_t) stack_A->list.head->data >= next_target->min
					  && (int)(intptr_t)stack_A->list.head->data <= next_target->max))
				pb(stack_A, stack_B);
			else
				ra(stack_A);
		}
		else
		{
			next_target_group(stack_A, target);
			next_target_group(stack_A,next_target);
		}
		if (next_target->name == 0)
			pb(stack_A, stack_B);
	}
}

void	divide_stack_by_group(t_stack *stack_A, t_stack *stack_B, t_group *target, double ratio)
{
	int size;
	int group;
	t_group *first_group;

	size = stack_A->stack_size;
	set_last_group(target, size, ratio);
	first_group = target;
	set_first_group(first_group, size, ratio);
	push_target_group(stack_A, stack_B, first_group);
}



int find_opt_step(t_stack *stack_A, t_stack *stack_B, int target) {
	int top_step = 0;
	int bot_step = 0;

	find_step_from_top(stack_B, target, &top_step);
	find_step_from_bot(stack_B, target, &bot_step);

	if (stack_A->list.last != NULL && (int) (intptr_t) stack_A->list.last->data == target) {
		rra(stack_A);
		return (3);
	} else if (top_step <= bot_step)
		return (1);
	else
		return (2);
}

void	push_and_rotate_till_target(t_stack *stack_A, t_stack *stack_B, int point, int step_result)
{
	while ((int)(intptr_t) stack_A->list.head->data != point && stack_B->list.head != NULL && stack_B->list.last != NULL)
	{
		if (stack_A->list.last != NULL && (int)(intptr_t) stack_A->list.last->data < (int)(intptr_t)stack_B->list.head->data)
		{
			pa(stack_A, stack_B);
			ra(stack_A);
		}
		if (step_result == 1 && stack_B->stack_size > 1)
			rb(stack_B);
		if (step_result == 2 && stack_B->stack_size > 1)
			rrb(stack_B);
		if ((int)(intptr_t) stack_B->list.head == point)
			pa(stack_A, stack_B);
	}
}

int is_sorted_target_range(t_stack *stack, t_group *target)
{
	t_doubly *node;

	node = stack->list.head;
	if ((int)(intptr_t)node->data != target->min)
		return (0);
	while ((int)(intptr_t)node->data != stack->max_total && node!= NULL)
	{
		if ((int)(intptr_t)node->data + 1 == (int)(intptr_t)node->next->data)
			node = node->next;
		else
			break;
	}
	if (node == NULL)
		return (1);
	else
		return (0);

}

void	uncompleted_range_sort(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	int range;
	int	point;
	int step_result;

	range = target->range;
	point = (int)(intptr_t)stack_A->list.head->data - 1;
	if (point < 0)
		return ;
	while (!is_sorted_target_range(stack_A, target) && point <= target->max)
	{
		point = (int)(intptr_t)stack_A->list.head->data - 1;
		if (is_sorted_target_range(stack_A, target))
			break  ;
		step_result = find_opt_step(stack_A, stack_B, point);
		if (step_result == 1 || step_result == 2) /* rb or rrb */
			push_and_rotate_till_target(stack_A, stack_B, point, step_result);
	}
}
