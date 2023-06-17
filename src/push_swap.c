/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/17 10:35:26 by minakim          ###   ########.fr       */
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

int ft_issort(int array[], int size)
{
	int i;
	i = size - 1;
	if (array[i] < array[i - 1])
		return (0);
	return (1);
}

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

/**
 * @param target_stack : target stack which hold total size of stack.
 * @param update : update total size value in target stack.
 * but if update == 0, reset total size as 0.
 */
void	update_stack_size(t_stack *target_stack, int update)
{
	if (update == 0)
		target_stack->total_size = 0;
	else
		target_stack->total_size += update;
}

/**
 * @brief
 * @param taken
 * @param put
 */
void	dbl_put_top(t_stack **taken, t_stack **put)
{
	t_doubly *node;
	node = dbl_newnode((*taken)->list.head->data);
	dbl_add_front(&(*put)->list, &node);
	dbl_del(&(*taken)->list, (*taken)->list.head);
}

/*
 *	sa (swap a): Swap the first 2 elements at the top of stack a.
 */
void	sa(t_stack *stack_A)
{
	dbl_swap_front_and_next(&(stack_A->list.head), &(stack_A->list.head->next), &(stack_A->list));
}

/*
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 */

void	sb(t_stack *stack_B)
{
	dbl_swap_front_and_next(&(stack_B->list.head), &(stack_B->list.head->next), &(stack_B->list));
}

/*
 * sa and sb at the same time.
 */
void	ss(t_stack *stack_A, t_stack *stack_B)
{
	dbl_swap_front_and_next(&(stack_A->list.head), &(stack_A->list.head->next), &(stack_A->list));
	dbl_swap_front_and_next(&(stack_B->list.head), &(stack_B->list.head->next), &(stack_B->list));
}

/*
 * pa (push a): Take the first element at the top of b and put it at the top of a.
 */
void	pa(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly *node;
	if (stack_B->list.head == NULL && stack_B->list.last == NULL)
		ft_error_basic("nothing in the stack");
	if (stack_A->list.head == NULL && stack_A->total_size == 0)
	{
		node = dbl_newnode((void *)(intptr_t )stack_B->list.head->data);
		stack_A->list.head = node;
		stack_A->list.last = NULL;
		dbl_del(&(stack_B->list), stack_B->list.head);
	}
	else
	{
		dbl_put_top(&stack_B, &stack_A);
	}
	update_stack_size(stack_A, +1);
	update_stack_size(stack_B, -1);
}

/*
 * pb (push b): Take the first element at the top of a and put it at the top of b.
 */
void	pb(t_stack *stack_A, t_stack *stack_B)
{
	t_doubly *node;
	if (stack_A->list.head == NULL && stack_A->list.last == NULL)
		ft_error_basic("nothing in the stack");
	if (stack_B->list.head == NULL)
	{
		node = dbl_newnode((void *)(intptr_t )stack_A->list.head->data);
		stack_B->list.head = node;
		stack_B->list.last = NULL;
		dbl_del(&(stack_A->list), stack_A->list.head);
	}
	else
		dbl_put_top(&stack_A, &stack_B);
	update_stack_size(stack_A, -1);
	update_stack_size(stack_B, +1);
}

void	rotate_node(t_lst *lst, t_doubly **node_one, t_doubly **node_two)
{
	t_doubly *temp;

	temp = *node_one;
}

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_A)
{
	t_doubly *temp;
	if (stack_A->list.head == NULL || stack_A->list.last == NULL)
		ft_error_basic("empty stack. can not rotate.");
	temp = stack_A->list.head;
	stack_A->list.head->next = stack_A->list.last->next;
	stack_A->list.head->prev = stack_A->list.last->prev;
	stack_A->list.last->next = temp->next;
	stack_A->list.last->prev = temp->prev;
	stack_A->list.head = stack_A->list.last;
	stack_A->list.last = stack_A->list.head;
	ft_printf("ra\n");
}

/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_B)
{
	t_doubly *temp;
	if (stack_B->list.head == NULL || stack_B->list.last == NULL)
		ft_error_basic("empty stack. can not rotate.");
	temp = stack_B->list.head;
	stack_B->list.head->next = stack_B->list.last->next;
	stack_B->list.head->prev = stack_B->list.last->prev;
	stack_B->list.last->next = temp->next;
	stack_B->list.last->prev = temp->prev;
	stack_B->list.head = stack_B->list.last;
	stack_B->list.last = stack_B->list.head;
	ft_printf("rb\n");
}

/*
 * ra and rb at the same time
 */
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
	ft_printf("rr\n");
}

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


	/* test function */
	print_stack(&stack_A);
	/* print stack_A */
	ft_printf("swap\n");
	sa(&stack_A);
	print_stack(&stack_A);

	ft_printf("\npb\n");
	pb(&stack_A, &stack_B);

	ft_printf("\nstact A\n");
	print_stack(&stack_A);

	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	ft_printf("\npb pb\n");
	pb(&stack_A, &stack_B);

	ft_printf("\nstact A\n");
	print_stack(&stack_A);

	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}


//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	t_doubly *node1 = malloc(sizeof(t_doubly));
//	t_doubly *node2 = malloc(sizeof(t_doubly));
//	t_doubly *node3 = malloc(sizeof(t_doubly));
//
//	node1->data = (void *)1;
//	node1->prev = NULL;
//	node1->next = node2;
//
//	node2->data = (void *)2;
//	node2->prev = node1;
//	node2->next = node3;
//
//	node3->data = (void *)3;
//	node3->prev = node2;
//	node3->next = NULL;
//
//	t_lst list;
//	list.head = node1;
//	list.last = node3;
//
//	t_doubly *front_node_ptr = node1;
//	t_doubly *next_node_ptr = node2;
//	t_doubly *next_next_node_ptr = node3;
//
//	printf("Before swap:\n");
//	printf("Node 1: %d\n", (int)(intptr_t)(front_node_ptr)->data);
//	printf("Node 2: %d\n", (int)(intptr_t)(next_node_ptr)->data);
//	printf("Node 3: %d\n", (int)(intptr_t)(next_next_node_ptr)->data);
//
//	dbl_swap_front_and_next(&front_node_ptr, &next_node_ptr, &list);
//
//	printf("\nAfter swap:\n");
//	printf("Node 1: %d\n", (int)(intptr_t)(front_node_ptr)->data);
//	printf("Node 2: %d\n", (int)(intptr_t)(next_node_ptr)->data);
//	printf("Node 3: %d\n", (int)(intptr_t)(next_next_node_ptr)->data);
//
//	free(node1);
//	free(node2);
//	free(node3);
//
//	return 0;
//}


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
