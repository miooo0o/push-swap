/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:05:55 by minakim           #+#    #+#             */
/*   Updated: 2023/07/11 19:27:28 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *
 * @param c
 * @return if c == ' ', return True, else return False.
 */
int ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}
/**
 *
 * @param str
 * @return
 */
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
		ft_error();
	return ((int)number);
}

/**
 *
 * @param array
 * @param size
 * @return
 */
int ft_issort_array(int array[], int size)
{
	int i;
	i = size - 1;
	if (array[i] < array[i - 1])
		return (0);
	return (1);
}

/**
 * @brief
 * @param stack
 * @return
 */
int	ft_issorted(t_stack *stack)
{
	t_doubly *node;

	node = stack->list.head;
	if ((int)(intptr_t)node->data != stack->min_total)
		return (0);
	while (node)
	{
		if (node->next == NULL)
			break ;
		if ((int)(intptr_t)node->data + 1 == (int)(intptr_t)node->next->data)
			node = node->next;
		else
			return (0);
	}
	if ((int)(intptr_t)node->data != stack->max_total)
		return (0);
	return (1);
}


int	is_sorted(t_stack *stack)
{
	t_doubly	*node;
	int			i;

	i = stack->stack_size;
	node = stack->list.head;
	if ((int)(intptr_t) node->data != stack->min_total)
		return (0);
	while (node)
	{
		if ((int)(intptr_t)node->data + 1 != (int)(intptr_t)node->next->data)
			return (0);
		node = node->next;
	}
	printf("node->data: %d\n", (int)(intptr_t)node->data);
	if ((int)(intptr_t) node->data != stack->max_total)
		return (0);
	return (1);
}

int	check_sorted(t_stack *stack)
{
	t_doubly *node;
	node = stack->list.head;
	while (node->next != NULL)
	{
		if ((int)(intptr_t)node->data > (int)(intptr_t)node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}