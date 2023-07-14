/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:59:35 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 15:34:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"
#include <stdio.h>

/* // commend out if need test
void	print_all_stack(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly	*a;
	t_doubly 	*b;

	a = stack_A->list.head;
	b = stack_B->list.head;
	printf("STACK A	| STACK B\n");
	while (a != NULL || b != NULL)
	{
		if(a == NULL)
		{
			printf("[ ]	| %d\n", (int)(intptr_t)b->data);
			b = b->next;
		}
		else if(b == NULL)
		{
			printf("%d	| [ ]\n", (int)(intptr_t)a->data);
			a = a->next;
		}
		else
		{
			printf("%d	| %d\n", (int)(intptr_t)a->data, (int)(intptr_t)b->data);
			a = a->next;
			b = b->next;
		}
	}
}*/
