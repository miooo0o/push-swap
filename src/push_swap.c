/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/02 22:57:54 by minakim          ###   ########.fr       */
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
	find_step_from_top(stack, num->data, &num->step_top);
	find_step_from_bot(stack, num->data, &num->step_bot);
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

	min.data = navigate_min(stack);
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


int	navigate_sec_min(t_stack *stack_A)
{
	int min;
	int	sec_min;
	int	value;
	t_doubly *node;

	node = stack_A->list.head;
	min = navigate_min(stack_A);
	if (min < 0)
		ft_error_basic("error, [need free]");
	sec_min = 1024;
	while (node != NULL)
	{
		value = (int)(intptr_t)node->data;
		if (value != min && value < sec_min)
			sec_min = value;
		node = node->next;
	}
	return (sec_min);
}

void	find_nums_and_check_step(t_stack *stack, t_num *min, t_num *sec_min)
{
	min->data = navigate_min(stack);
	sec_min->data = navigate_sec_min(stack);
	find_step_from_top(stack, min->data, &min->step_top);
	find_step_from_bot(stack, min->data, &min->step_bot);
	find_step_from_top(stack, sec_min->data, &sec_min->step_top);
	find_step_from_bot(stack, sec_min->data, &sec_min->step_bot);
}

int	check_special_case(t_stack *stack, int *trigger)
{
	t_num min;
	t_num sec_min;

	find_nums_and_check_step(stack, &min, &sec_min);
	*trigger = 0;
	if (min.step_bot == min.step_top)
	{
		if (sec_min.step_top == 0)
			*trigger = 1; // ra, 나중에 rb
		if (sec_min.step_bot == 0)
			*trigger = 2; // rra , 나중에 rb
	}
	return (*trigger);
}


void	sort_five(t_stack *stack_A, t_stack *stack_B)
{
	int trigger;

	if (ft_issorted(stack_A))
		return ;
	trigger = check_special_case(stack_A, &trigger);

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
//	sort_four(&stack_A, &stack_B);
	sort_five(&stack_A, &stack_B);
//	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}