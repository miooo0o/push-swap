/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/29 16:59:06 by minakim          ###   ########.fr       */
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

void	sort_two(t_stack *stack)
{
	if (stack->list.head->data > stack->list.head->next->data)
		sa(stack);
}

int	ft_issort(t_stack *stack)
{
	t_doubly *node;

	node = stack->list.head;
	while (node != NULL && node->next != NULL)
	{
		if ((int)(intptr_t)node->data + 1 == (int)(intptr_t)node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

/*
1 2 3 // return ;
3 2 1 //

3 1 2 // ra

2 3 1 // rra
2 1 3 // sa
1 3 2 //
*/

/*
2 3 4 5 / 5 > a && a <= 100 (100) ratio 0.12 / <= 500 0.08 ratio
		small num								large num
*/

void	sort_three(t_stack *stack)
{
	int	one;
	int	two;
	int three;

	one = (int)(intptr_t)(stack)->list.head->data;
	two = (int)(intptr_t)(stack)->list.head->next->data;
	three = (int)(intptr_t)(stack)->list.head->next->next->data;
	if (ft_issort(stack))
		return ;
	if (one > three && three > two)
		ra(stack);
	if (two > three && three < one)
		rra(stack);
	if (three > one && one > two)
		sa(stack);
}

//void	divide_stack(t_stack *stack_A, t_stack *stack_B)
//{
//	int	ratio;
//	int size;
//
//	size = stack_A->total_size;
//
//
//	ratio = 0.12 * size;
//
//
//	ratio + 0.12 * size
//
//
//}

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
			rb(stack_B);
		}
		else if ((int)(intptr_t)node->data >= small_pivot && (int)(intptr_t)node->data <= large_pivot)
			pb(stack_A, stack_B);
		else
			ra(stack_A);
		node = next_node;
		i++;
	}
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

	print_all_stack(&stack_A, &stack_B);
	sort_three(&stack_A);
	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}