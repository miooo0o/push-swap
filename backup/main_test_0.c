/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:40:35 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 17:40:37 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;
	int 	num[MAX];

	initialize_stack(&stack_A);
	av_to_array(ac, av, num);
	init_stack_a_with_arr(&stack_A, num, ac);
	init_stack_b(&stack_B);


	/* test function */
	print_stack(&stack_A);

	/* print stack_A */

	/* sa */
	ft_printf("\nsa\n");
	sa(&stack_A);
	print_stack(&stack_A);

	/* sa pb */
	ft_printf("\nsa pb\n");
	pb(&stack_A, &stack_B);
	ft_printf("\nstact A\n");
	print_stack(&stack_A);
	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	/* sa pb pb */
	ft_printf("\nsa pb pb\n");
	pb(&stack_A, &stack_B);
	ft_printf("\nstact A\n");
	print_stack(&stack_A);
	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	/* sa pb pb ra */
	ft_printf("\nsa pb pb ra\n");
	ra(&stack_A);
	ft_printf("\nstact A\n");
	print_stack(&stack_A);
	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	/* sa pb pb ra rra */
	ft_printf("\nsa pb pb ra rra\n");
	rra(&stack_A);
	ft_printf("\nstact A\n");
	print_stack(&stack_A);
	ft_printf("\nstactB\n");
	print_stack(&stack_B);

	/* free */
	dbl_listfree(&(stack_A.list));
	dbl_listfree(&(stack_B.list));
}