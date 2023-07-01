/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/01 17:18:32 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if ((intptr_t)(stack->list.head->data) > (intptr_t)(stack)->list.head->next->next->data
	&& ((intptr_t)(stack)->list.head->data > (intptr_t)(stack)->list.head->next->data))
		ra(stack);
	if ((intptr_t)(stack)->list.head->next->data > (intptr_t)(stack)->list.head->next->next->data)
		rra(stack);
	if ((intptr_t)(stack)->list.head->data > (intptr_t)(stack)->list.head->next->data)
		sa(stack);
}

int 	navigate_min(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		node = stack->list.head;
		result = (int)(intptr_t) node->data;
		while (node != NULL)
		{
			if (result > (int)(intptr_t)(node->data))
				result = (int)(intptr_t) node->data;
			node = node->next;
		}
		return (result);
	}
}

int 	navigate_max(t_stack *stack)
{
	t_doubly *node;
	int result;

	if (ft_issorted(stack))
		return (-1);
	else
	{
		node = stack->list.last;
		result = (int)(intptr_t) node->data;
		while (node != NULL)
		{
			if (result < (int)(intptr_t) node->data)
				result = (int)(intptr_t) node->data;
			node = node->prev;
		}
		return (result);
	}
}

void	find_step_from_bot(t_stack *stack, int target, int *step)
{
	t_doubly *node;
	*step = 0;
	node = stack->list.last;
	while (node->prev != NULL && node != NULL)
	{
		if ((int)(intptr_t) node->data == target)
			break;
		node = node->prev;
		(*step)++;
	}
}

void	find_step_from_top(t_stack *stack, int target, int *step)
{
	t_doubly *node;

	node = stack->list.head;
	*step = 0;
	while (node->next != NULL && node != NULL)
	{
		if ((int)(intptr_t) node->data == target)
			break;
		node = node->next;
		(*step)++;
	}
}

#define RUN_TOP 1
#define RUN_BOT 0

int	opt_by_step(t_stack *stack, t_num *num)
{
	find_step_from_top(stack, num->i, &num->step_top);
	find_step_from_bot(stack, num->i, &num->step_bot);
//	ft_printf("top %d\n", num->step_top);
//	ft_printf("bot %d\n", num->step_bot);
	if (num->step_top < num->step_bot)
		return (RUN_TOP);
	else
		return (RUN_BOT);
}

void	find_min_and_bring_top(t_stack *stack)
{
	t_num min;
	t_doubly *node;

	min.i = navigate_min(stack);
	node = stack->list.head;
	if (opt_by_step(stack, &min) == RUN_TOP)
	{
		while ((int)(intptr_t)node->data != min.i)
		{
			ra(stack);
			node = stack->list.head;
		}
	}
	else
	{
		while ((int)(intptr_t)node->data != min.i)
		{
			rra(stack);
			node = stack->list.head;
		}
	}
}

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

// TODO : small, large로 나눠서 끝내기 (5 >= && 100 <=, <= 500)

// TODO: finish this function
/*
void	divide_stack(t_stack *stack_A, t_stack *stack_B)
{
	int	ratio;
	int size;

	size = stack_A->total_size;
	ratio = 0.12 * size;
	ratio + 0.12 * size

}
*/


int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_B);

//	sort_three(&stack_A);
//	print_all_stack(&stack_A, &stack_B);
	sort_four(&stack_A, &stack_B);
//	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}