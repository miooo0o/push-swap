/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:35 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:43:44 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"
#include <stdio.h>
void	print_all_stack(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly	*A;
	t_doubly 	*B;

	A = stack_A->list.head;
	B = stack_B->list.head;

	printf("STACK A	| STACK B\n");

	while (A != NULL || B != NULL)
	{
		if(A == NULL)
		{
			printf("[ ]	| %d\n", (int)(intptr_t)B->data);
			B = B->next;
		}
		else if(B == NULL)
		{
			printf("%d	| [ ]\n", (int)(intptr_t)A->data);
			A = A->next;
		}
		else
		{
			printf("%d	| %d\n", (int)(intptr_t)A->data, (int)(intptr_t)B->data);
			A = A->next;
			B = B->next;
		}
	}
}
