/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:31:44 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:45:40 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

/**
 *
 * @param stack
 * @param info
 * @param ac
 */
void	init_stack_a_with_arr(t_stack *stack, t_info *info)
{
	t_doubly	*new_node;
	t_doubly	*head_node;
	int			i;

	i = -1;
	head_node = NULL;
	parsing_data_to_index(info, stack);
	while (++i < stack->stack_size)
	{
		new_node = dbl_newnode((void *)(intptr_t)info->index[i]);
		if (!new_node)
			ft_error_lstfree(stack, NULL);
		if (!dbl_add_back(&(stack->list), &new_node))
			ft_error_lstfree(stack, NULL);
		if (i == 0 && head_node == NULL)
			head_node = new_node;
	}
	if (stack->list.head != head_node || stack->list.last != new_node)
		ft_error_lstfree(stack, NULL);
	stack->max_total = navigate_max(stack);
	stack->min_total = navigate_min(stack);
}

void	init_stack_b(t_stack *stack_A, t_stack *stack_B)
{
	initialize_stack(stack_B);
	stack_B->stack_size = 0;
	stack_B->min_total = stack_A->min_total;
	stack_B->max_total = stack_A->max_total;
}

void	initialize_stack(t_stack *stack)
{
	stack->list.head = NULL;
	stack->list.last = NULL;
	stack->min_total = 0;
	stack->max_total = 0;
}
