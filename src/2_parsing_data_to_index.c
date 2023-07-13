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
#include <stdio.h>

int		argv_check(char c);
void	change_data_to_index(t_info *info, int length, int value[]);

int validate_input(char c)
{
	if (ft_isprint(c) && !argv_check(c) && !ft_isspace(c) )
		return (0);
	return (1);
}

static int	number_compare(int num1, char num2)
{
	return (num1 - num2);
}

int validate_same_num(int array[], int a)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < a && j > i)
	{
		j = i + 1;
		while (j < a && j != i)
		{
			if (array[i] == array[j])
				ft_error();
			j++;
		}
		i++;
	}
}


int validate_and_convert(int ac, char **av, int array[], int *a)
{
	int i;
	int	j;
	int from;

	i = 0;
	while (++i < ac && *a < MAX)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!validate_input(av[i][j]))
				ft_error();
			if (argv_check(av[i][j]))
			{
				from = j;
				while (argv_check(av[i][j]))
					j++;
				array[(*a)++] = ft_atoi_from_to(av[i], from, j);
				validate_same_num(array, (*a));
			}
			else
				j++;
		}
	}
	return (*a);
}

void convert_argv_to_int(int ac, char **av, t_info *info)
{
	int a;
	int array[MAX];

	a = 0;
	a = validate_and_convert(ac, av, array, &a);
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
		info->index[i] = -1;

	find_max_and_min(info->array, value, stack->stack_size);
	change_data_to_index(info, stack->stack_size, value);
}

void	same_number_check(int index[], int length)
{
	int i;
	int count;

	count = 0;
	printf("[%d]\n", length);
	while (count < length)
	{
		i = count;
		while (i < length)
		{
			printf("%d\n", index[count]);
			if (index[count] == index[i] && index[i] != -1)
				ft_error();
			i++;
		}
		count++;
	}
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