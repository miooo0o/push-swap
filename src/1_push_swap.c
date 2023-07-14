/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 17:32:35 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, t_group *target)
{
	if (stack_a->stack_size < 1)
		ft_error();
	else if (stack_a->stack_size < 6)
	{
		sort_by_hard_coding(stack_a, stack_b);
		push_swap_lstfree(stack_a, stack_b);
	}
	else
	{
		target->base_range = set_range(stack_a->stack_size);
		divide_stack_by_ratio(stack_a, stack_b, target);
		sort_loop(stack_a, stack_b, target);
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_info	info;
	t_group	target;

	if (ac < 2 || av[1][0] == '\0' || *av[0] == '\0')
		ft_error();
	else
	{
		ft_bzero(&info.array, MAX);
		convert_argv_to_int(ac, av, &info);
		initialize_stack(&stack_a);
		init_stack_a_with_arr(&stack_a, &info);
		init_stack_b(&stack_a, &stack_b);
		if (check_sorted(&stack_a) && stack_b.list.head == NULL)
		{
			dbl_listfree(&(stack_a.list));
			exit(1);
		}
		push_swap(&stack_a, &stack_b, &target);
	}
}
