/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/20 16:02:30 by minakim          ###   ########.fr       */
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

//void sort(t_stack *stack_A, t_stack *stack_B) {
//	int pivot;
//	int size;
//	int	i;
//
//	if (is_empty(stack_A) || stack_size(stack_A) == 1)
//		return ;
//	pivot = peek(stack_A);
//	size = stack_size(stack_A);
//	if (size == -1)
//		ft_error_basic("error");
//	i = -1;
//}


int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	int 	num[MAX];

	initialize_stack(&stack_A);
	av_to_array(ac, av, num);
	init_stack_a_with_arr(&stack_A, num, ac);
	init_stack_b(&stack_B);
	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}