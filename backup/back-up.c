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


/* TODO: start this function */
/*
 *	sa (swap a): Swap the first 2 elements at the top of stack a.
 */
void	sa(t_stack **stack_A)
{

}

/*
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 */
void	sb();

/*
 * sa and sb at the same time.
 */
void	ss();

/*
 * pa (push a): Take the first element at the top of b and put it at the top of a.
 */
void	pa();

/*
 * pb (push b): Take the first element at the top of a and put it at the top of b.
 */
void	pb();

/*
 * ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra();

/*
 * rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb();

/*
 * ra and rb at the same time
 */
void	rr();

/*
 * rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 */
void	rra();

/*
 * rrb (reverse rotate b): Shift down all elements of stack b by 1.
 * The last element becomes the first one.
 */
void	rrb();

/*
 * rrr : rra and rrb at the same time.
 */
void	rrr();


int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	int 	result;
	int 	*num;
	num = av_to_array(ac, av);

	int i = 0;
	while ()
	{
		ft_printf("%d\n", num[i]);
		i++;
	}
	init_stack_value(&stack_A);

}

/* test main */
//#include <assert.h>
//
//int main(int ac, char **av) {
//	t_stack stack_A;
//	t_stack stack_B;
//
//	/* init value */
//	stack_A.total_size = 0;
//	stack_B.total_size = 0;
//
//	/* Test ft_atoi_pushswap() */
//	assert(ft_atoi_pushswap("123") == 123);
//	assert(ft_atoi_pushswap("-123") == -123);
//	assert(ft_atoi_pushswap("0") == 0);
//	assert(ft_atoi_pushswap("+123") == 123);
//
//	/* Test case for init_stack_A */
//	char *test_case[] = {"./push_swap", "1", "2", "3"};
//	init_stack_A(4, test_case, &stack_A);
//	assert(stack_A.total_size == 3);
//	assert(stack_A.num[0] == 1);
//	assert(stack_A.num[1] == 2);
//	assert(stack_A.num[2] == 3);
//
//	ft_printf("All tests passed.\n");
//	return 0;
//}


void	dbl_swap_a_front_b_front(t_stack **stack1, t_stack **stack2)
{
	t_doubly *node1;
	t_doubly *node2;
	t_doubly *temp;

	node1 = (*stack1)->list.head;
	node2 = (*stack2)->list.head;
	if (node1->prev != NULL || node2->prev != NULL)
		ft_error_basic("input should be front node, [!] not free list");
	temp = node1;
	node1->next->prev = node2;
	node2->next->prev = node1;
	node1->prev = NULL;
	node2->prev = NULL;
	node1->next = node2->next;
	node2->next = temp->next;
	(*stack1)->list.head = node2;
	(*stack2)->list.head = node1;
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
