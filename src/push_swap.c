/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/08 12:30:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

long int	ft_atoi_pushswap(const char *str)
{
	long int	number;
	int			sign;
	size_t		i;

	number = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && (str[i] != '\0'))
	{
		number = (number * 10) + (str[i] - 48);
		if (number > 2147483647 && sign == 1 || number > 2147483648 && sign == -1)
			ft_error_basic("input is not valid");
		i++;
	}
	if (str[i] && (str[i] < 48 || str[i] > 57))
		ft_error_basic("input is not valid");
	return (number * sign);
}

static int compare_num(t_stack *stack_A)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack_A->total_size)
	{
		j = i + 1;
		while (j < stack_A->total_size)
		{
			if (stack_A->num[i] == stack_A->num[j])
				return (0);
			j++;
		}
	}
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
		new_node = dbl_newnode((void *)(long int)stack->num[i]);
		if (!new_node)
			ft_error_basic("error, but didn't set free something.");
		dbl_add_back(&(stack->list), &new_node);
		if (i == 0 && head_node == NULL)
			head_node = new_node;
	}
	if (stack->list.head != head_node || stack->list.last != new_node)
		ft_error_basic("I should free list");
	ft_printf("Stack A is finished set up.");
}


void parse_input_and_init(int ac, char** av, t_stack *stack_A)
{
	int i;
	int j;

	i = 1;
	j = 0;
	stack_A->total_size = ac - 1;
	while (i < ac && j < stack_A->total_size)
		stack_A->num[j++] = ft_atoi_pushswap(av[i++]);
	if (compare_num(stack_A))
	{
		init_new_stack(stack_A);
	}
	else
		ft_error_basic("same number");
}

void dbl_free_all(t_lst *list)
{
	t_doubly *current = list->head;
	t_doubly *next_node;

	while (current != NULL) {
		next_node = current->next;
		free(current);
		current = next_node;
	}
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
		ft_error_basic("input number should be bigger then");
	init_stack_value(stack_A);
	parse_input_and_init(ac, av, stack_A);
	dbl_free_all(&(stack_A->list));

}


//int main(int ac, char **av)
//{
//   	t_stack stack_A;
//    t_stack stack_B;
//
//	int i;
//	i = 0;
//
//	t_doubly *test = (t_doubly *) malloc(sizeof(t_doubly));
//	init_stack_A(ac, av, &stack_A);
//}


#include <assert.h>

int main(int ac, char **av) {
	t_stack stack_A;
	t_stack stack_B;

	/* init value */
	stack_A.total_size = 0;
	stack_B.total_size = 0;

	/* Test ft_atoi_pushswap() */
	assert(ft_atoi_pushswap("123") == 123);
	assert(ft_atoi_pushswap("-123") == -123);
	assert(ft_atoi_pushswap("0") == 0);
	assert(ft_atoi_pushswap("+123") == 123);

	/* Test case for init_stack_A */
	char *test_case[] = {"./push_swap", "1", "2", "3"};
	init_stack_A(4, test_case, &stack_A);
	assert(stack_A.total_size == 3);
	assert(stack_A.num[0] == 1);
	assert(stack_A.num[1] == 2);
	assert(stack_A.num[2] == 3);

	ft_printf("All tests passed.\n");
	return 0;
}
