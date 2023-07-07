/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/06 16:30:06 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_range_count(t_stack *stack)
{
	int size;
	int count;

	size = stack->max_total;
	count = 0;
	count = size / stack->range;
	return (count);
}

void	set_range_and_ratio(t_stack *stack)
{
	stack->ratio = 0.12;
	stack->range = (int)(stack->max_total * stack->ratio);
	stack->range_count = get_range_count(stack);
	stack->count_sum = stack->range_count;
}

void	range_group_to_stack(t_stack *stack_A, t_stack *stack_B)
{
	int	size;
	int i;
	t_doubly *node;

	size = stack_A->stack_size;
	i = 0;
	while (++i < size)
	{
		node = stack_A->list.head;
		if ((int)(intptr_t)node->data < stack_A->range)
		{
			pb(stack_A, stack_B);
			rb(stack_B);
		}
		else if ((int)(intptr_t)node->data > (int)(stack_A->range + stack_A->ratio * size))
			ra(stack_A);
		else
			pb(stack_A, stack_B);
	}
}

void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B)
{
	int	range;
	int size;
	t_doubly *node;

	size = stack_A->stack_size;
	range = stack_A->range;
	while (range <= size)
	{
		range_group_to_stack(stack_A, stack_B);
		range = range + (int)(size * (stack_A->ratio * 2));
	}
	size = stack_A->stack_size;
	if (size - 1 > 0)
		size = size - 1;
	while (size > 0)
	{
		node = stack_A->list.head;
		if ((int)(intptr_t) node->data == stack_A->max_total)
			ra(stack_A);
		pb(stack_A, stack_B);
		size--;
	}
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

t_doubly *get_stack_a_bottom_head(t_stack *stack_A)
{
	t_doubly *bot_head;
	t_doubly *node;

	node = stack_A->list.head;
	bot_head = NULL;
	while ((int)(intptr_t) node->data != stack_A->max_total && node != NULL)
		node = node->next;
	if ((int)(intptr_t)node->prev->data == stack_A->max_total)
		bot_head = node;
	return (bot_head);
}

int	is_sorted_complete(t_stack *stack, t_doubly *start, t_doubly *end)
{
	t_doubly *node;

	node = start;
	while (node != end && node != NULL)
	{
		if ((int)(intptr_t) node->data + 1 != (int)(intptr_t)node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int	is_sorted_complete_reverse(t_stack *stack, t_doubly *start, t_doubly *end)
{
	t_doubly *node;

	node = start;
	while (node != end && node != NULL)
	{
		if ((int)(intptr_t) node->data - 1 != (int)(intptr_t)node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

t_doubly *get_top_node_if_sorted_complete(t_stack *stack, t_doubly *start, t_doubly *end)
{
	t_doubly *node;
	t_doubly *top_node;

	node = start;
	top_node = NULL;
	while (node != end && node != NULL)
	{
		if (top_node == NULL)
		{
			if ((int)(intptr_t) node->data + 1 == (int)(intptr_t)node->next->data)
				top_node = node;
		}
		node = node->next;
	}
	return (top_node);
}

void	is_reverse_sorted_in_stack_b(t_stack *stack_A, t_stack *stack_B)
{
	int size;
	int	i;
	t_doubly *temp;

	if (!is_sorted_complete_reverse(stack_B,stack_B->list.head,NULL))
		return ;
	temp = stack_B->list.head;
	size = 0;
	while (stack_B->list.head != NULL)
	{
		if ((int)(intptr_t) temp->data + 1 != (int)(intptr_t)temp->next->data)
			break;
		temp = temp->next;
		size++;
	}
	i = -1;
	while (++i < size)
		pa(stack_A, stack_B);
}

void	verify_and_restore_bot_sorted_order(t_stack *stack_A)
{
	t_doubly	*last_node;
	int			size;
	int 		i;

	last_node = stack_A->list.last;
	size = 0;
	while (last_node->prev != NULL)
	{
		if (!(int)(intptr_t) last_node->data - 1 == (int)(intptr_t)last_node->prev->data)
			break ;
		last_node = last_node->prev;
		size++;
	}
	i = -1;
	while (++i < size)
		rra(stack_A);
}


void	get_target_range(t_stack *stack, int target_range[])
{
	int max_count;

	max_count = stack->count_sum;
	if (stack->range_count == max_count && stack->max_total % max_count != 0)
	{
		target_range[0] = stack->max_total - stack->max_total % stack->range;
		target_range[1] = stack->max_total;
		target_range[2] = stack->max_total;
	}
	else
	{
		target_range[0] = stack->max_total - stack->range * stack->range_count;
		target_range[1] = stack->max_total;
		target_range[2] = stack->max_total;
	}
}


int check_range_sorted_complete(t_stack *stack)
{
	int size;
	int start;
	int	end;
	t_doubly *node;

	if (stack->range_count == stack->count_sum)
		size = stack->max_total % stack->count_sum;
	else
		size = stack->range;
	start = stack->range_count * stack->range;
	node = stack->list.head;
	if (start != (int)(intptr_t) node->data)
		return (0);
	end = start + stack->range - 1;
	while (--size > 0 && start != end && node != NULL)
	{
		node = node->next;
		start += 1;
		if (start != (int)(intptr_t) stack->list.head->data)
			return (0);
	}
	if (size == 0 && (int)(intptr_t) node->data == end)
		return (1);
	else
		return (0);
}

int 	update_range_count(t_stack *stack_A, t_stack *stack_B)
{

	if (stack_A->range_count == 0)
		return (0 /* stack_A의 솔트가 완료됐는지 확인하는 함수 */);
	if (check_range_sorted_complete(stack_A))
	{
		stack_A->range_count -= 1;
		if (stack_A->range_count == 0)
			update_range_count(stack_A, stack_B); // or /* stack_A의 솔트가 완료됐는지 확인하는 함수 */
	}
	return (stack_A->range_count);
}

void	check_stack_b_and_push(t_stack *stack_A, t_stack *stack_B)
{
	int target_range[3];

	get_target_range(stack_A, target_range,)
	if (stack_B->list.head)
}

/* if there is sorted nodes range in stacks, do sorting */
void	push_range_to_stack(t_stack *stack_A, t_stack *stack_B)
{
	if (is_sorted_till_max(stack_A))
	{
		if ((int)(intptr_t) stack_A->list.head->data - 1 == (int)(intptr_t) stack_B->list.head->data)
		{
			is_reverse_sorted_in_stack_b(stack_A, stack_B);
			push_range_to_stack(stack_A, stack_B);
		}
		else if (/* bot is exist */)
		{
			if ((int)(intptr_t) stack_A->list.head->data - 1 == (int)(intptr_t) stack_A->list.last->data)
			{
				verify_and_restore_bot_sorted_order(stack_A);
				push_range_to_stack(stack_A, stack_B);
			}
			if (/* if bot sorted */)
				check_stack_b_and_push(stack_A, stack_B);
			else
				/* sort bot */
		}
		else if ()// if bot is not exit...
		{
			check_stack_b_and_push(stack_A, stack_B);
			/* sort bot */
		}
	}
	else
	{

	}
}


void	opt(t_stack * stack_A, t_stack * stack_B)
{
	int target_range[3];
	int count;

	count = 1;
}


int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_A, &stack_B);

	// init 파트에 넣어야 하고, 그 전에 ratio를 지정하는 함수를 만들어야 함.
	set_range_and_ratio(&stack_A);
	set_range_and_ratio(&stack_B);


//	divide_stack_by_ratio(&stack_A, &stack_B);
	ft_printf("range count : %d\n", stack_A.range_count);


	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}

// 54 95 69 41 64 18 66 82 28 56 91 4 9 81 90 13 24 59 7 38 29 0 63 47 23 77 93 94 10 3 21 19 52 20 72 78 80 1 33 86 50 87 27 26 32 43 84 45 49 11 68 14 89 31 74 48 99 34 8 40 12 16 75