/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/05/24 16:16:07 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_isnumber_str(char *string)
{
	int i;
	i = -1;
	while (string[++i] != '\0')
	{
		if (ft_isalnum(string[i]) != 1)
			return (0);
	}
	return (1);
}

int     get_malloc_size(char **num_temp)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (num_temp[++i] != NULL)
	{
		if (ft_isnumber_str(num_temp[i]) == FALSE)
			ft_error_basic();
		count++;
	}
	return (count);
}

void    parse_input(char **av, int ac, t_info *info)
{
	int     i;
	char    **num_temp;
	int     size;

	size = 0;
	i = -1;
	while (++i < ac)
	{
		num_temp = NULL;
		num_temp = ft_split(av[i], ' ');
		if (get_malloc_size(num_temp) != 1)
			ft_error_basic();
		info->num[i] = ft_atoi(num_temp[i]);
		ft_free_2d(num_temp);
	}
	info->malloc_size = size;
	if (info->malloc_size)
		ft_printf("all numbers stored.");
}

t_stack *init_input_to_stack_A(int ac, char **av, t_info *info)
{
	// input will parse to parse_input()
	if (ac == 1)
		ft_error_basic("input number");
	parse_input(av, ac, info);
}

int main(int ac, char **av)
{
    t_stack *stack_A;
    t_stack *stack_B;
	t_info  info;

	stack_A = init_input_to_stack_A(ac, av, &info);
}
