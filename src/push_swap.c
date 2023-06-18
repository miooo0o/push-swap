/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 12:40:53 by minakim          ###   ########.fr       */
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
 * @brief taken 스택의 해드 노드를 put 스택의 해드 노드로 바꾸는 어쩌구
 * @note "스택의 해드 노드"여야만 어쩌구
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
	if (stack_A->list.head == NULL)
		ft_error_basic("empty stack");
	if (stack_A->list.head->next == NULL)
		ft_error_listfree("there should be more than 2 node", &stack_A->list);
	dbl_swap_front_and_next(&(stack_A->list.head), &(stack_A->list.head->next), &(stack_A->list));
}

/*
 * sb (swap b): Swap the first 2 elements at the top of stack b.
 */

void	sb(t_stack *stack_B)
{
	if (stack_B->list.head == NULL)
		ft_error_basic("empty stack");
	if (stack_B->list.head->next == NULL)
		ft_error_listfree("there should be more than 2 node", &stack_B->list);
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
		dbl_put_top(&stack_B, &stack_A);
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

/**
 * @brief ra (rotate a): Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 */
void	ra(t_stack *stack_A)
{
	dbl_swap_front_and_last(&(stack_A->list.head), &(stack_A->list.last), &stack_A->list);
}

/**
 * @brief rb (rotate b): Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 */
void	rb(t_stack *stack_B)
{
	dbl_swap_front_and_last(&(stack_B->list.head), &(stack_B->list.last), &stack_B->list);
}

/*
 * ra and rb at the same time
 */
void	rr(t_stack *stack_A, t_stack *stack_B)
{
	ra(stack_A);
	rb(stack_B);
}


/* TODO: 여기부터 */
/**
 * @brief rra (reverse rotate a): Shift down all elements of stack a by 1.
 * The last element becomes the first one.
 * @param stack_A
 */
void	rra(t_stack *stack_A)
{
	t_doubly *node;

	node = dbl_newnode((void *)(intptr_t )stack_A->list.last->data);
	dbl_del(&stack_A->list, stack_A->list.last);
}

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

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}