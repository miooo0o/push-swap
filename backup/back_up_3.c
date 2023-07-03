/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_up_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 21:46:22 by minakim           #+#    #+#             */
/*   Updated: 2023/07/03 21:46:51 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* not used */
void	find_sec_min_and_bring_top(t_stack *stack)
{
	t_num min;
	t_doubly *node;

	min.data = navigate_sec_min(stack);
	node = stack->list.head;
	if (opt_by_step(stack, &min) == RUN_TOP)
	{
		while ((int)(intptr_t)node->data != min.data)
		{
			ra(stack);
			node = stack->list.head;
		}
	}
	else
	{
		while ((int)(intptr_t)node->data != min.data)
		{
			rra(stack);
			node = stack->list.head;
		}
	}
}