/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_valid_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:31:03 by minakim           #+#    #+#             */
/*   Updated: 2023/07/14 13:31:07 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../include/push_swap.h"

int	validate_same_num(int array[], int a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < a && j > i)
	{
		j = i + 1;
		while (j < a && j != i)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_input(char c)
{
	if (ft_isprint(c) && !argv_check(c) && !ft_isspace(c))
		return (0);
	return (1);
}

int	argv_check(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}
/* need to finish function
from = j;
while (argv_check(av[i][j]))
j++;
array[(*a)++] = ft_atoi_from_to(av[i], from, j);
if (!validate_same_num(array, (*a)))
ft_error();
*/

/**
 * @brief Validates and converts command line arguments into an integer array.
 * This function truncates the string passed in as an argument and converts it to
 * an int. It checks if the int is the same number as an already stored int,
 * and if it is, it returns an error message and exits
 * @return The updated value of the current index after converting the arguments.
 * @param ac The number of command line arguments.
 * @param av An array of command line argument strings.
 * @param array The integer array to store the converted values.
 * @param a A pointer to the current index of the array.
 */
int	validate_and_convert(int ac, char **av, int array[], int *a)
{
	int	i;
	int	j;
	int	from;

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
				if (!validate_same_num(array, (*a)))
					ft_error();
			}
			else
				j++;
		}
	}
	return (*a);
}

/**
 * @brief Converts command line arguments into an integer array and stores it in
 * the 'info' structure.
 * @param ac The number of command line arguments.
 * @param av An array of command line argument strings.
 * @param info A pointer to the 'info' structure to store the converted
 * integer array.
 */
void	convert_argv_to_int(int ac, char **av, t_info *info, t_stack *stack)
{
	int	a;
	int	array[MAX];

	a = 0;
	a = validate_and_convert(ac, av, array, &a);
	if (a < 1)
		ft_error();
	stack->stack_size = a;
	ft_memcpy(info->array, array, a * sizeof(int));
}
