/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/07/03 21:52:11 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// TODO : (5 > && 100 <=, <= 500)


//void	divide_stack(t_stack *stack_A, t_stack *stack_B)
//{
//	int	ratio;
//	int size;
//
//	size = stack_A->total_size;
//	ratio = 0.12 * size;
//	ratio + 0.12 * size
//
//}



int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	t_info	info;

	initialize_stack(&stack_A);
	av_to_array(ac, av, &info);
	init_stack_a_with_arr(&stack_A, &info, ac);
	init_stack_b(&stack_B);

	sort_five(&stack_A, &stack_B);
//	print_all_stack(&stack_A, &stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}