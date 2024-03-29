/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:36:28 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 18:09:14 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 *
 * @param stack
 * @param min
 * @param sec_min
 */
void	find_nums_and_check_step(t_stack *stack, t_num *min, t_num *sec_min)
{
	min->data = navigate_min(stack);
	sec_min->data = navigate_sec_min(stack);
	find_step_from_top(stack, min->data, &min->step_top);
	find_step_from_bot(stack, min->data, &min->step_bot);
	find_step_from_top(stack, sec_min->data, &sec_min->step_top);
	find_step_from_bot(stack, sec_min->data, &sec_min->step_bot);
}

/**
 *
 * @param stack
 * @param trigger
 * @return
 */
int	check_special_case(t_stack *stack, int *trigger)
{
	t_num	min;
	t_num	sec_min;

	find_nums_and_check_step(stack, &min, &sec_min);
	*trigger = 0;
	if (min.step_bot == min.step_top)
	{
		if (sec_min.step_top == 0)
			*trigger = 1;
		if (sec_min.step_bot == 0)
			*trigger = 2;
	}
	return (*trigger);
}

/**
 *
 * @param stack_A
 * @param stack_B
 */
void	if_sec_min_top(t_stack *stack_A, t_stack *stack_B)
{
	pb(stack_A, stack_B);
	find_min_and_bring_top(stack_A);
	if (!ft_issorted(stack_A))
	{
		pb(stack_A, stack_B);
		sort_three(stack_A);
		sb(stack_B);
		pa(stack_A, stack_B);
		pa(stack_A, stack_B);
	}
	else
	{
		pa(stack_A, stack_B);
		sa(stack_A);
	}
}

/**
 *
 * @param stack_A
 * @param stack_B
 */
void	if_sec_min_bot(t_stack *stack_A, t_stack *stack_B)
{
	rra(stack_A);
	if_sec_min_top(stack_A, stack_B);
}
