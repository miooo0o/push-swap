//
// Created by minakim on 5/24/23.
//

int    ft_isnumber_str(char *string)
{
	int i;
	i = -1;
	while (string[++i] != '\0')
	{
		if (ft_isalnum(string[i]) != 1)
			return (0);
	}
	return (1);
}

static int  get_malloc_count(char **num_temp);
// get how much malloc size i need


void    parse_input(char **av, int end)
{
	// with ft_split, store value to int * or int[]
	// in this care [ 1 23 "12 39 39" 12 ], how can I parse?
	int i;
	int count;
	char **num_temp;

	i = 0;
	count = 0;
	while (i < end)
	{
		num_temp = ft_split(av[i], ' ');
		count = get_malloc_count();
	}
}

int partition(int num[], int start, int end)
{
	int pivot;
	int i;
	int index;
	int	temp;


	pivot = num[end];
	index = start;
	i = start;
	while (i < end)
	{
		if (num[i] <= pivot)
		{
			temp = num[i];
			num[i] = num[index];
			num[index] = temp;
			index++;
		}
		i++;
	}

}

void	quicksort(int num[], int start, int end)
{
	int index;
	if (start < end)
	{
		index = partition(num, start, end);
		quicksort(num, start, index - 1);
		quicksort(num, index + 1, end);
	}
	else
	{
		return ;
	}
}


/* start */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/12 18:39:24 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi_pushswap(const char *str)
{
	long long	number;
	int			sign;
	int 		size_checker;

	number = 0;
	sign = 1;
	size_checker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		number = (number * 10) + (*str - 48);
		str++;
		size_checker++;
	}
	number = number * sign;
	if (*str != '\0' || size_checker > 10 || number > 2147483647 || number < -2147483648)
		ft_error_basic("input is not valid");
	return ((int)number);
}

static int compare_num(int *array, int total_size)
{
	int	i;
	int	j;
	int array_size;

	i = -1;
	array_size = 0;
	while (++i <total_size)
	{
		j = i + 1;
		while (j < total_size)
		{
			if (array[j] > array[j + 1])
				array_size++;
			if (array[i] == array[j])
				return (0);
			j++;
		}
	}
	if (array_size == 0)
		ft_error_basic("");
	return (1);
}

void	init_new_stack(t_stack *stack)
{
	t_doubly	*new_node;
	t_doubly	*head_node;
	int 		i;

	i = -1;
	head_node = NULL;
	while (++i < stack->total_size)
	{
		new_node = NULL;
		new_node = dbl_newnode((void *)(long int)stack->array[i]);
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


int	*av_to_array(int ac, char **av)
{
	int i;
	int j;
	int total_size;
	int *array;
	i = 1;
	j = 0;
	if (ac < 2)
		ft_error_basic("empty argument.");
	if (ac < 3)
		ft_error_basic("there is no numbers can sort.");
	total_size = ac - 1;
	array = malloc(sizeof(int) * total_size);
	while (i < ac && j < total_size)
		array[j++] = ft_atoi_pushswap(av[i++]);
	compare_num(array, total_size);
	return (array);
}

void	init_stack_value(t_stack *stack)
{
	stack->list.head = NULL;
	stack->list.last = NULL;
	stack->total_size = 0;
}

//void	init_stack_A(int ac, char **av, t_stack *stack_A)
//{
//	if (ac < 2)
//		ft_error_basic("empty argument.");
//	if (ac < 3)
//		ft_error_basic("there is no numbers can sort.");
//	init_stack_value(stack_A);
//	parse_input_and_init(ac, av, stack_A);
//
//}


void	init_stack_B(t_stack *stack_A, t_stack *stack_B)
{
	stack_B->total_size = stack_A->total_size;
	stack_B->list.head = NULL;
	stack_B->list.last = NULL;
	ft_progress("done", "Stack B set up");
}


/* test done */
void test_dbl_swap(t_doubly **front_node_ptr, t_doubly **next_node_ptr, t_lst *list)
{
	t_doubly *front_node;
	t_doubly *next_node;
	t_doubly *next_next_node;

	if (front_node_ptr == NULL || next_node_ptr == NULL || list == NULL \
	|| (*front_node_ptr)->next != (*next_node_ptr) || front_node->prev != NULL)
		assert(!"Error: empty node input");
	front_node = *front_node_ptr;
	next_node = (*front_node_ptr)->next;
	next_next_node = next_node->next;
	next_node->prev = front_node->prev;
	next_node->next = front_node;
	front_node->prev = next_node;
	front_node->next = next_next_node;
	if (next_next_node != NULL)
		next_next_node->prev = front_node;
	else
		list->last = front_node;
	if (list->head == *front_node_ptr)
		list->head = next_node;
	front_node_ptr = &front_node;
	next_node_ptr = &next_node;
	(*front_node_ptr)->next = next_next_node;
}



/* test function */
print_stack(&stack_A);

/* print stack_A */

/* sa */
ft_printf("\nsa\n");
sa(&stack_A);
print_stack(&stack_A);

/* sa pb */
ft_printf("\nsa pb\n");
pb(&stack_A, &stack_B);
ft_printf("\nstact A\n");
print_stack(&stack_A);
ft_printf("\nstactB\n");
print_stack(&stack_B);

/* sa pb pb */
ft_printf("\nsa pb pb\n");
pb(&stack_A, &stack_B);
ft_printf("\nstact A\n");
print_stack(&stack_A);
ft_printf("\nstactB\n");
print_stack(&stack_B);

/* sa pb pb ra */
ft_printf("\nsa pb pb ra\n");
ra(&stack_A);
ft_printf("\nstact A\n");
print_stack(&stack_A);
ft_printf("\nstactB\n");
print_stack(&stack_B);

/* sa pb pb ra rra */
ft_printf("\nsa pb pb ra rra\n");
rra(&stack_A);
ft_printf("\nstact A\n");
print_stack(&stack_A);
ft_printf("\nstactB\n");
print_stack(&stack_B);



/*
 *

void	ra_1(t_stack *stack_A)
{
	t_doubly *head_node;

	if (stack_A == NULL || stack_A->list.head == NULL \
		|| stack_A->list.last == NULL \
		|| stack_A->list.head == stack_A->list.last)
		return ;
	head_node = stack_A->list.head;
	stack_A->list.head = head_node->next;
	stack_A->list.head->prev = NULL;
	head_node->prev = stack_A->list.last;
	stack_A->list.last->next = head_node;
	head_node->next = NULL;
	stack_A->list.last = head_node;
	ft_printf("ra\n");
}

void	rb_1(t_stack *stack)
{
	t_doubly *head_node;

	if (stack == NULL || stack->list.head == NULL \
	|| stack->list.last == NULL \
		|| stack->list.head == stack->list.last)
		return ;
	head_node = stack->list.head;
	stack->list.head = head_node->next;
	stack->list.head->prev = NULL;
	head_node->prev = stack->list.last;
	stack->list.last->next = head_node;
	head_node->next = NULL;
	stack->list.last = head_node;
	ft_printf("rb\n");
}

 */