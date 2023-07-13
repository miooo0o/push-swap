/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:34:12 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:45:10 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

int		argv_check(char c);
void	change_data_to_index(t_info *info, int length, int value[]);

/**
 *
 * @param ac
 * @param av
 * @param info
 */
void convert_argv_to_int(int ac, char **av, t_info *info)
{
	int i;
	int	j;
	int a;
	int from;
	int array[MAX];

	i = 0;
	a = 0;
	while (++i < ac && a < MAX)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (argv_check(av[i][j]))
			{
				from = j;
				while (argv_check(av[i][j]))
					j++;
				array[a++] = ft_atoi_from_to(av[i], from, j);
			}
			else
				j++;
		}
	}
	if (a < 1)
		ft_error();
	ft_memcpy(info->array, array, a * sizeof(int));
}

/**
 *
 * @param c
 * @return
 */
int argv_check(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

/**
 *
 * @param info
 * @param stack
 */
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

/**
 *
 * @param info
 * @param length
 * @param value
 */
void change_data_to_index(t_info *info, int length, int value[])
{
	int i;
	int peek;
	int rank;

	peek = value[0];
	rank = 0;
	while (peek <= value[1])
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

/**
 *
 * @param array
 * @param value
 * @param length
 */
void	find_max_and_min(int array[], int value[], int length)
{
	int i;
	i = 0;

	value[0] = array[i];
	value[1] = array[i];
	while(i < length)
	{
		if (value[0] > array[i])
			value[0] = array[i];
		if (value[1] < array[i])
			value[1] = array[i];
		i++;
	}
}
