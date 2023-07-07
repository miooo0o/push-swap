/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/07 13:55:14 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		else if ((int)(intptr_t)node->data > (int)(range + (int)(ratio * size)))
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

	divide_stack_by_ratio(&stack_A, &stack_B, 0.12);


	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}

// 54 95 69 41 64 18 66 82 28 56 91 4 9 81 90 13 24 59 7 38 29 0 63 47 23 77 93 94 10 3 21 19 52 20 72 78 80 1 33 86 50 87 27 26 32 43 84 45 49 11 68 14 89 31 74 48 99 34 8 40 12 16 75