/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:31:44 by minakim           #+#    #+#             */
/*   Updated: 2023/07/07 13:53:55 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"


void	check_argc(int ac)
{
	if (ac < 2)
		ft_error_basic("empty argument.");
	if (ac < 3)
		ft_error_basic("there are not enough numbers to sort.");
}

void	av_to_array(int ac, char **av, t_info *info)
{
	int	i;
	int	j;
	int	k;
	int	total_size;
	int	trigger;

	check_argc(ac);
	trigger = 0;
	i = 1;
	j = 0;
	total_size = ac - 1;
	while (i < ac && j < total_size)
	{
		info->array[j++] = ft_atoi_pushswap(av[i++]);
		if (j > 1 && ft_issort_array(info->array, j))
			trigger++;
		k = 0;
		while (k < j - 1)
		{
			if (info->array[k] == info->array[j - 1])
				ft_error_basic("same number.");
			k++;
		}
	}
	if (trigger == 0)
		ft_error_basic("arguments are already sorted.");
}


void	initialize_stack(t_stack *stack)
{
	stack->list.head = NULL;
	stack->list.last = NULL;
	stack->stack_size = 0;
	stack->min_total = 0;
	stack->max_total = 0;
}

void	find_max_and_min(int array[], int value[], int length)
{
	int i;
	i = 0;
	value[Small] = array[i];
	value[Large] = array[i];
	while(i < length)
	{
		if (value[Small] > array[i])
			value[Small] = array[i];
		if (value[Large] < array[i])
			value[Large] = array[i];
		i++;
	}
}

void change_data_to_index(t_info *info, int length, int value[])
{
	int i;
	int peek;
	int rank;

	peek = value[Small];
	rank = 0;
	while (peek <= value[Large])
	{
		i = 0;
		while(i < length)
		{
			if (info->array[i] == peek)
			{
				info->index[i] = rank;
				rank++;
			}
			i++;
		}
		peek++;
	}
}

void	parsing_data_to_index(t_info *info, t_stack *stack)
{
	int value[2];
	int i;

	i = -1;
	while (++i < stack->stack_size)
		info->index[i] = info->array[i];
	find_max_and_min(info->array, value, stack->stack_size);
	change_data_to_index(info, stack->stack_size, value);
}

void	init_stack_a_with_arr(t_stack *stack, t_info *info, int ac)
{
	t_doubly	*new_node;
	t_doubly	*head_node;
	int 		i;

	i = -1;
	head_node = NULL;
	stack->stack_size = ac - 1;
	parsing_data_to_index(info, stack);
	while (++i < stack->stack_size)
	{
		new_node = dbl_newnode((void *)(intptr_t)info->index[i]);
		if (!new_node)
			ft_error_basic("error, but didn't set free something.");
		dbl_add_back(&(stack->list), &new_node);
		if (i == 0 && head_node == NULL)
			head_node = new_node;
	}
	if (stack->list.head != head_node || stack->list.last != new_node)
		ft_error_listfree("node set up fail.", &(stack->list));
	stack->max_total = navigate_max(stack);
	stack->min_total = navigate_min(stack);
}

void	init_stack_b(t_stack *stack_A, t_stack *stack_B)
{
	initialize_stack(stack_B);
	stack_B->min_total = stack_A->min_total;
	stack_B->max_total = stack_A->max_total;
}
