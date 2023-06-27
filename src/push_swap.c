/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/27 22:31:56 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_stack *stack)
{
	if (stack->total_size == 0 && stack->list.head == NULL && stack->list.last == NULL)
		return (1);
	return (0);
}

int peek(t_stack *stack)
{
	return ((int)(intptr_t)stack->list.head->data);
}

int stack_size(t_stack *stack)
{
	t_doubly *node;
	int count;

	if (stack->list.head == NULL)
		return (0);
	if (stack->list.head == stack->list.last)
		return (1);
	node = stack->list.head;
	count = 1;
	while (node->next != NULL)
	{
		node = node->next;
		count++;
	}
	if (count == stack->total_size)
		return (count);
	return (-1);
}

void	divide_stack_into_three(t_stack *stack_A, t_stack *stack_B)
{
	int small_pivot;
	int large_pivot;
	int	i;
	int count;
	t_doubly *node;
	t_doubly *next_node;

	i = 0;
	small_pivot = (stack_A->total_size * 1) / 3;
	large_pivot = (stack_A->total_size * 2) / 3;
	ft_printf("small :%d\n", small_pivot);
	ft_printf("large :%d\n", large_pivot);

	node = stack_A->list.head;
	count = stack_A->total_size;

	while (i < count)
	{
		next_node = node->next;
		if ((int)(intptr_t)node->data < small_pivot || (int)(intptr_t)node->data == 0)
		{
			pb(stack_A, stack_B);
			if (stack_B->total_size > 1)
				rb(stack_B);
		}
		else if ((int)(intptr_t)node->data >= small_pivot && (int)(intptr_t)node->data <= large_pivot)
		{
			pb(stack_A, stack_B);
		}
		else
			ra(stack_A);
		node = next_node;
		i++;
	}
}

/* 얼마나 움직여서 해결 가능한지 확인하는 함수들을 만들기 */

void test_ra_operation(t_stack *stack_A)
{
	ft_printf("Before rotation:\n");
	print_stack(stack_A); // Assuming you have a print function for stack_A

	rb(stack_A);

	ft_printf("After rotation:\n");
	print_stack(stack_A); // Assuming you have a print function for stack_A
}


int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_B);

	ft_printf("Before divide_stack_into_three:\n");
	print_stack(&stack_B);

	divide_stack_into_three(&stack_A, &stack_B);
//	print_all_stack(&stack_A, &stack_B);
	ft_printf("After divide_stack_into_three:\n");
	print_stack(&stack_B);


	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}