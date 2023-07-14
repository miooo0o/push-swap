/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_hard_coding.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:31:38 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 18:09:18 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

void	sort_by_hard_coding(t_stack *stack_A, t_stack *stack_B)
{
	if (stack_A->stack_size == 2)
		sort_two(stack_A);
	else if (stack_A->stack_size == 3)
		sort_three(stack_A);
	else if (stack_A->stack_size == 4)
		sort_four(stack_A, stack_B);
	else if (stack_A->stack_size == 5)
		sort_five(stack_A, stack_B);
	else
		return ;
}

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

	if (ft_issorted(stack))
		return ;
	if ((intptr_t)(stack->list.head->data)
			> (intptr_t)(stack)->list.head->next->next->data
		&& ((intptr_t)(stack)->list.head->data
			> (intptr_t)(stack)->list.head->next->data))
		ra(stack);
	if ((intptr_t)(stack)->list.head->next->data
			> (intptr_t)(stack)->list.head->next->next->data)
		rra(stack);
	if ((intptr_t)(stack)->list.head->data
		> (intptr_t)(stack)->list.head->next->data)
		sa(stack);
}

/**
 *
 * @param stack_A
 * @param stack_B
 */
void	sort_four(t_stack *stack_A, t_stack *stack_B)
{
	if (ft_issorted(stack_A))
		return ;
	find_min_and_bring_top(stack_A);
	if (!ft_issorted(stack_A))
	{
		pb(stack_A, stack_B);
		sort_three(stack_A);
		pa(stack_A, stack_B);
	}
}

/**
 *
 * @param stack_A
 * @param stack_B
 */
void	sort_five(t_stack *stack_A, t_stack *stack_B)
{
	int trigger;

	if (ft_issorted(stack_A))
		return ;
	trigger = check_special_case(stack_A, &trigger);
	if (trigger == 1)
		if_sec_min_top(stack_A, stack_B);
	else if (trigger == 2)
		if_sec_min_bot(stack_A, stack_B);
	else
	{
		find_min_and_bring_top(stack_A);
		pb(stack_A, stack_B);
		sort_four(stack_A, stack_B);
		pa(stack_A, stack_B);
	}
}
