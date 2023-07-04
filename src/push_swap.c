/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/04 19:46:39 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// TODO : (5 > && 100 <=, <= 500)


void	range_group_to_stack(t_stack *stack_A, t_stack *stack_B, int range, double ratio)
{
	int	size;
	int i;
	t_doubly *node;

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
		else if ((int)(intptr_t)node->data > (int)(range + ratio * size))
			ra(stack_A);
		else
			pb(stack_A, stack_B);
	}
}

void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B, double ratio)
{
	int	range;
	int size;
	int max;
	t_doubly *node;

	size = stack_A->stack_size;
	max = stack_A->max_total;
	range = (int)(size * ratio);
	while (range <= size)
	{
		range_group_to_stack(stack_A, stack_B, range, ratio);
		range = range + (int)(size * (ratio * 2));
	}
	size = stack_A->stack_size;
	if (size - 1 > 0)
		size = size - 1;
	while (size > 0)
	{
		node = stack_A->list.head;
		if ((int)(intptr_t) node->data == max)
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

t_doubly *get_bot_node_if_sorted_complete(t_stack *stack, t_doubly *start, t_doubly *end)
{
	t_doubly *node;
	t_doubly *top_node;
	t_doubly *bot_node;

	top_node = get_top_node_if_sorted_complete(stack, start, end);
	bot_node = NULL;
	if (top_node == NULL)
		return (bot_node);
	node = top_node;
	while (node != end && node != NULL)
	{
		if ((int)(intptr_t) node->data + 1 != (int)(intptr_t)node->next->data)
			break;
		bot_node = node;
		node = node->next;
	}
	return (bot_node);
}

void	is_reverse_sorted_in_stack_b(t_stack *stack_A, t_stack *stack_B)
{
	int size;
	int	i;
	t_doubly *temp;

	if (!is_sorted_complete_reverse(stack_B,stack_B->list.head,NULL))
		return ;
	temp = stack_B->list.head;
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

/* if there is sorted nodes range in stacks, do sorting */
void	push_range_to_stack(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly *head_node;
	t_doubly *last_node;

	head_node = stack_A->list.head;
	last_node = stack_A->list.last;

	/* check : element to pa is match with top element in stack A */
	if (head_node->data - 1 == stack_B->list.head)
	{
		is_reverse_sorted_in_stack_b(stack_A, stack_B);
		push_range_to_stack(stack_A, stack_B);
	}
	else if ((int)(intptr_t) head_node->data - 1 == (int)(intptr_t)last_node->data) /* check : elements on bot_stack_A match with top element in stack A */
	{
		verify_and_restore_bot_sorted_order(stack_A);
		push_range_to_stack(stack_A, stack_B);
	}
	else
		return ;
}

void	check_and_correct_top_sorted_order(t_stack *stack_A)
{
	t_doubly *node;

	node = stack_A->list.head;
	if ((int)(intptr_t) node->data != (int)(intptr_t)node->next->data - 1)
		ra(stack_A);
}

void	before_push_to_a(t_stack *stack_A, t_stack *stack_B, double ratio)
{

	int			scope;
	static int	ran_max;
	static int	ran_min;
	static int 	ran_mid;

	scope = (int)(ratio * stack_A->range);
	ran_max = stack_A->max_total - 1;
	ran_min = ran_max - scope;
	ran_mid = ran_min + (int)(ratio * 0.5);
	while (stack_B->list.head != NULL)
	{

		if ((int)(intptr_t)stack_B->list.head->data ==
			(int)(intptr_t)stack_A->list.head->data - 1)
		{
			pa(stack_A, stack_B);
			push_range_to_stack(stack_A, stack_B);
		}
		else if ((int)(intptr_t) stack_B->list.head->data >= ran_min
			&& (int)(intptr_t) stack_B->list.head->data < ran_mid)
			rb(stack_B);
		else if ((int)(intptr_t) stack_B->list.head->data <= ran_max
				 && (int)(intptr_t) stack_B->list.head->data >= ran_mid)
			/* pa, check it sort or not
			 * -> if yes : back to loop,
			 * -> if not : but gap it only 1 [99 - - 97 ],
			 * keep on top and change trigger for sa, and back to loop
			 * -> if not : send to stack a bot
			 * and check bot sort state
			 * -> if yes, back to loop
			 * -> if yes, and if can push to top stack a, push_range_to_stack
			 * -> if not (sort bot ?) */
	}
}


//void	opt_divided_stack_sort(t_stack *stack_A, t_stack *stack_B)
//{
//	while (stack_B->stack_size > 0)
//	{
//		push_range_to_stack(stack_A, stack_B);
//		if (is_sorted_complete(stack_A, stack_A->list.head, NULL))
//		{
//			pa(stack_A, stack_B);
//			check_and_correct_top_sorted_order(stack_A);
//		}
//		else if ((int)(intptr_t)stack_B->list.head->data ==
//				(int)(intptr_t) stack_A->list.head->data - 1)
//		{
//			pa(stack_A, stack_B);
//			check_and_restore_sorted_order(stack_A, stack_B);
//
//		}
//		else if ((int)(intptr_t)stack_B->list.head->data >
//			(int)(intptr_t) stack_A->list.last->data)
//		{
//			pa(stack_A, stack_B);
//			check_and_correct_top_sorted_order(stack_A);
//		}
//		else
//		{
//
//		}
//	}
//}

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_A, &stack_B);
//	sort_five(&stack_A, &stack_B);
	divide_stack_by_ratio(&stack_A, &stack_B, 0.12);
	opt_divided_stack_sort(&stack_A, &stack_B);
//	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}