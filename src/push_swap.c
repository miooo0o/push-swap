/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/29 22:18:20 by minakim          ###   ########.fr       */
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
 * @brief sort
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
	if (ft_issort(stack))
		return ;
	if (one > three && three > two)
		ra(stack);
	if (two > three && three < one)
		rra(stack);
	if (three > one && one > two)
		sa(stack);
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