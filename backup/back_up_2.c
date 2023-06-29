/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_up_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:13:37 by minakim           #+#    #+#             */
/*   Updated: 2023/06/29 22:14:14 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_empty(t_stack *stack)
{
	if (stack->total_size == 0 && stack->list.head == NULL && stack->list.last == NULL)
		return (1);
	return (0);
}

int peek(t_stack *stack)
{
	return ((int)(intptr_t)stack->list.head->data);
}

int stack_size(t_stack *stack)
{
	t_doubly *node;
	int count;

	if (stack->list.head == NULL)
		return (0);
	if (stack->list.head == stack->list.last)
		return (1);
	node = stack->list.head;
	count = 1;
	while (node->next != NULL)
	{
		node = node->next;
		count++;
	}
	if (count == stack->total_size)
		return (count);
	return (-1);
}

void	divide_stack_into_three(t_stack *stack_A, t_stack *stack_B)
{
	int small_pivot;
	int large_pivot;
	int	i;
	int count;
	t_doubly *node;
	t_doubly *next_node;

	i = 0;
	small_pivot = (stack_A->total_size * 1) / 3;
	large_pivot = (stack_A->total_size * 2) / 3;
	ft_printf("small :%d\n", small_pivot);
	ft_printf("large :%d\n", large_pivot);

	node = stack_A->list.head;
	count = stack_A->total_size;

	while (i < count)
	{
		next_node = node->next;
		if ((int)(intptr_t)node->data < small_pivot || (int)(intptr_t)node->data == 0)
		{
			pb(stack_A, stack_B);
			rb(stack_B);
		}
		else if ((int)(intptr_t)node->data >= small_pivot && (int)(intptr_t)node->data <= large_pivot)
			pb(stack_A, stack_B);
		else
			ra(stack_A);
		node = next_node;
		i++;
	}
}