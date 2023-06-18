/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:41:17 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 17:12:20 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

long int	ft_atoi_pushswap(const char *str)
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

static int compare_num(t_stack *stack_A)
{
	int	i;
	int	j;
	int array_size;

	i = -1;
	array_size = 0;
	while (++i < stack_A->total_size)
	{
		j = i + 1;
		while (j < stack_A->total_size)
		{
			if (stack_A->array[j] > stack_A->array[j + 1])
				array_size++;
			if (stack_A->array[i] == stack_A->array[j])
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

char **parsing_av(int ac, char **av)
{

}

void parse_input_and_init(int ac, char** av, t_stack *stack_A)
{
	int i;
	int j;
	char **parsed_results;

	i = 1;
	j = 0;
	parsed_results = parsing_av(ac, av);
	stack_A->total_size = ac - 1;
	while (i < ac && j < stack_A->total_size)
		stack_A->array[j++] = ft_atoi_pushswap(parsed_results[i++]);
	ft_free_2d(parsed_results);
	if (compare_num(stack_A))
		init_new_stack(stack_A);
	else
		ft_error_listfree("same number in the list.", &(stack_A->list));
}

void	init_stack_value(t_stack *stack)
{
	stack->list.head = NULL;
	stack->list.last = NULL;
	stack->total_size = 0;
}

void	init_stack_A(int ac, char **av, t_stack *stack_A)
{
	if (ac < 2)
		ft_error_basic("empty argument.");
	if (ac < 3)
		ft_error_basic("there is no numbers can sort.");
	init_stack_value(stack_A);
	parse_input_and_init(ac, av, stack_A);

}


void	init_stack_B(t_stack *stack_A, t_stack *stack_B)
{
	stack_B->total_size = stack_A->total_size;
	stack_B->list.head = NULL;
	stack_B->list.last = NULL;
	ft_progress("done", "Stack B set up");
}

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
	int 	num[MAX];

	/* debug [OK] */
	init_stack_A(ac, av, &stack_A);
	init_stack_B(&stack_A, &stack_B);
	dbl_listfree(&(stack_A.list));
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
