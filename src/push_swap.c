/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 17:47:40 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_argc(int ac)
{
	if (ac < 2)
		ft_error_basic("empty argument.");
	if (ac < 3)
		ft_error_basic("there are not enough numbers to sort.");
}

void	av_to_array(int ac, char **av, int array[])
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
		array[j++] = ft_atoi_pushswap(av[i++]);
		if (j > 1 && ft_issort(array, j))
			trigger++;
		k = 0;
		while (k < j - 1)
		{
			if (array[k] == array[j - 1])
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
	stack->total_size = 0;
}

void	init_stack_a_with_arr(t_stack *stack, int array[], int ac)
{
	t_doubly	*new_node;
	t_doubly	*head_node;
	int 		i;

	i = -1;
	head_node = NULL;
	stack->total_size = ac - 1;
	while (++i < stack->total_size)
	{
		new_node = dbl_newnode((void *)(intptr_t)array[i]);
		if (!new_node)
			ft_error_basic("error, but didn't set free something.");
		dbl_add_back(&(stack->list), &new_node);
		if (i == 0 && head_node == NULL)
			head_node = new_node;
	}
	if (stack->list.head != head_node || stack->list.last != new_node)
		ft_error_listfree("node set up fail.", &(stack->list));
	ft_progress("done", "Stack A set up");
}

void	init_stack_b(t_stack *stack_B)
{
	initialize_stack(stack_B);
	ft_progress("done", "Stack B set up");
}

/*
 * test function. it will print "data"
 * */
void print_head(t_doubly *head)
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

void print_list(t_lst *list)
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

void print_stack(t_stack *stack)
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

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	int 	num[MAX];

	initialize_stack(&stack_A);
	av_to_array(ac, av, num);
	init_stack_a_with_arr(&stack_A, num, ac);
	init_stack_b(&stack_B);

}