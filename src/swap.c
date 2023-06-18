/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:28 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 17:58:12 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 * @brief sa (swap a): Swap the first 2 elements at the top of stack a.
 */
void	sa(t_stack *stack_A)
{
	if (stack_A->list.head == NULL)
		ft_error_basic("empty stack");
	if (stack_A->list.head->next == NULL)
		ft_error_listfree("there should be more than 2 node", &stack_A->list);
	dbl_swap_front_and_next(&(stack_A->list.head), &(stack_A->list.head->next), \
	&(stack_A->list));
}

/**
 * @brief b (swap b): Swap the first 2 elements at the top of stack b.
 */

void	sb(t_stack *stack_B)
{
	if (stack_B->list.head == NULL)
		ft_error_basic("empty stack");
	if (stack_B->list.head->next == NULL)
		ft_error_listfree("there should be more than 2 node", &stack_B->list);
	dbl_swap_front_and_next(&(stack_B->list.head), &(stack_B->list.head->next), \
	&(stack_B->list));
}

/**
 * @brief sa and sb at the same time.
 */
void	ss(t_stack *stack_A, t_stack *stack_B)
{
	sa(stack_A);
	sb(stack_B);
}
