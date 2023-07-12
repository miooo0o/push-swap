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

void	push_swap(t_stack *stack_A, t_stack *stack_B, t_group *target)
{
	if (stack_A->stack_size < 6)
	{
		sort_by_hard_coding(stack_A, stack_B);
		push_swap_lstfree(stack_A, stack_B);
	}
	else
	{
		target->base_range = set_range(stack_A->stack_size);
		divide_stack_by_ratio(stack_A, stack_B, target);
		sort_loop(stack_A, stack_B, target);
	}
}

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;
	t_group target;

	if (ac < 2 || av[1][0] == '\0' || *av[0] == '\0')
		ft_error();
	else
	{
		convert_argv_to_int(ac, av, &info);
		initialize_stack(&stack_A);
		init_stack_a_with_arr(&stack_A, &info);
		init_stack_b(&stack_A, &stack_B);
		if (check_sorted(&stack_A) && stack_B.list.head == NULL)
		{
			dbl_listfree(&(stack_A.list));
			exit(1);
		}
		push_swap(&stack_A, &stack_B, &target);
	}
}
