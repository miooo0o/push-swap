/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_not_know.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:12:34 by minakim           #+#    #+#             */
/*   Updated: 2023/07/06 13:12:38 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	check_and_correct_top_sorted_order(t_stack *stack_A)
{
	t_doubly *node;

	node = stack_A->list.head;
	if ((int)(intptr_t) node->data != (int)(intptr_t)node->next->data - 1)
		ra(stack_A);
}

t_doubly *get_bot_node_if_sorted_complete(t_stack *stack, t_doubly *start, t_doubly *end)
{
	t_doubly *node;
	t_doubly *top_node;
	t_doubly *bot_node;

	top_node = get_top_node_if_sorted_complete(stack, start, end);
	bot_node = NULL;
	if (top_node == NULL)
		return (bot_node);
	node = top_node;
	while (node != end && node != NULL)
	{
		if ((int)(intptr_t) node->data + 1 != (int)(intptr_t)node->next->data)
			break;
		bot_node = node;
		node = node->next;
	}
	return (bot_node);
}

