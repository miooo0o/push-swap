/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/30 23:44:30 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief
 * @param stack
 */
void	sort_two(t_stack *stack)
{
	if (stack->list.head->data > stack->list.head->next->data)
		sa(stack);
}


/**
 * @brief
 * @param stack
 */
void	sort_three(t_stack *stack)
{
	int	one;
	int	two;
	int three;

	one = (int)(intptr_t)(stack)->list.head->data;
	two = (int)(intptr_t)(stack)->list.head->next->data;
	three = (int)(intptr_t)(stack)->list.head->next->next->data;
	if (ft_issorted(stack))
		return ;
	if (one > three && three > two)
		ra(stack);
	if (two > three && three < one)
		rra(stack);
	if (three > one && one > two)
		sa(stack);
}

int 	find_min_in_list(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		result = 0;
		node = stack->list.head;
		result = (int)(intptr_t) node->data;
		while (node->next != NULL && node != NULL)
		{
			if (result > (int)(intptr_t) node->data)
				result = (int)(intptr_t) node->data;
			node = node->next;
		}
		return (result);
	}
}

int 	find_max_in_list(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		result = 0;
		node = stack->list.head;
		result = (int)(intptr_t) node->data;
		while (node->next != NULL && node != NULL)
		{
			if (result < (int)(intptr_t) node->data)
				result = (int)(intptr_t) node->data;
			node = node->next;
		}
		return (result);
	}
}

void

void	sort_four(t_stack *stack)
{
	int min;
	int max;

	min = find_min_in_list(stack);
	max = find_max_in_list(stack);
	if (min < 0 || max < 0)
		ft_error_basic("can not found right number. [need free]");


}

// TODO : hard-coding 끝내기, small, large로 나눠서 끝내기 (5 >= && 100 <=, <= 500)

// TODO: finish this function
/*
void	divide_stack(t_stack *stack_A, t_stack *stack_B)
{
	int	ratio;
	int size;

	size = stack_A->total_size;
	ratio = 0.12 * size;
	ratio + 0.12 * size

}
*/


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