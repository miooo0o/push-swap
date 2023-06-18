/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 11:05:55 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 11:06:54 by minakim          ###   ########.fr       */
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