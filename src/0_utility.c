/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_utility.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi■■■■■ <mi■■■■■@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:05:55 by minakim           #+#    #+#             */
/*   Updated: 2023/07/17 17:17:13 by mi■■■■■          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

/**
 * @brief
 * @param stack
 * @return
 */
int	ft_issorted(t_stack *stack)
{
	t_doubly	*node;

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

/**
 *
 * @param stack
 * @return
 */
int	check_sorted(t_stack *stack)
{
	t_doubly	*node;

	node = stack->list.head;
	while (node->next != NULL)
	{
		if ((int)(intptr_t)node->data > (int)(intptr_t)node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

/**
 *
 * @param str
 * @return
 */
int	ft_atoi_from_to(const char *str, int from, int to)
{
	long long	number;
	int			sign;
	int			size_checker;

	number = 0;
	sign = 1;
	size_checker = 0;
	if (str[from] == '-')
		sign = -1;
	if (str[from] == '+' || str[from] == '-')
		from++;
	while (str[from] != '\0' && ft_isdigit(str[from]) && \
			!ft_isspace(str[from]) && from < to)
	{
		number = (number * 10) + (str[from] - 48);
		from++;
		size_checker++;
	}
	number = number * sign;
	if (size_checker > 10 || number > 2147483647 || number < -2147483648)
		ft_error();
	return ((int)number);
}
