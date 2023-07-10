/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:43:28 by minakim           #+#    #+#             */
/*   Updated: 2023/07/10 19:23:39 by minakim          ###   ########.fr       */
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
		ft_error();
	if (stack_A->list.head->next == NULL)
		ft_error_lstfree(stack_A, NULL);
	dbl_swap_front_and_next(&(stack_A->list.head), &(stack_A->list.head->next), \
	&(stack_A->list));
	write(1, "sa\n", 4);
}

/**
 * @brief b (swap b): Swap the first 2 elements at the top of stack b.
 */

void	sb(t_stack *stack_B)
{
	if (stack_B->list.head == NULL)
		ft_error();
	if (stack_B->list.head->next == NULL)
		ft_error_lstfree(NULL, stack_B);
	dbl_swap_front_and_next(&(stack_B->list.head), &(stack_B->list.head->next), \
	&(stack_B->list));
	write(1, "sb\n", 4);
}

/**
 * @brief sa and sb at the same time.
 */
void	ss(t_stack *stack_A, t_stack *stack_B)
{
	sa(stack_A);
	sb(stack_B);
	write(1, "ss\n", 4);
}
