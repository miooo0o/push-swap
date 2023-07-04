/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:35 by minakim           #+#    #+#             */
/*   Updated: 2023/06/20 13:27:04 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

/* all test functions to print stack. */
void	print_head(t_doubly *head)
{
	t_doubly	*current;
	int 		i;

	i = 0;
	current = head;
	while (current != NULL)
	{
		ft_printf("[%d] %d\n", i, (int)(intptr_t)current->data);
		current = current->next;
		i++;
	}
}

void	print_list(t_lst *list)
{
	t_doubly	*current;
	int 		i;

	if (list == NULL)
		assert(!"Error: empty list input");
	i = 0;
	ft_printf("\nall list\n");
	current = list->head;
	while (current != NULL)
	{
		ft_printf("[%d] %d\n", i, (int)(intptr_t)current->data);
		current = current->next;
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	t_doubly	*current;
	int 		i;

	i = 0;
	current = stack->list.head;
	while (current != NULL)
	{
		ft_printf("[%d] %d\n", i, (int)(intptr_t)current->data);
		current = current->next;
		i++;
	}
}

void	print_all_stack(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly	*A;
	t_doubly 	*B;

	A = stack_A->list.head;
	B = stack_B->list.head;

	ft_printf("STACK A	| STACK B\n");

	while (A != NULL || B != NULL)
	{
		if(A == NULL)
		{
			ft_printf("[ ]	| %d\n", (int)(intptr_t)B->data);
			B = B->next;
		}
		else if(B == NULL)
		{
			ft_printf("%d	| [ ]\n", (int)(intptr_t)A->data);
			A = A->next;
		}
		else
		{
			ft_printf("%d	| %d\n", (int)(intptr_t)A->data, (int)(intptr_t)B->data);
			A = A->next;
			B = B->next;
		}
	}
}