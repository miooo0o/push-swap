/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:17:02 by minakim           #+#    #+#             */
/*   Updated: 2023/07/11 19:43:03 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../include/push_swap.h"

int	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	push_swap_lstfree(t_stack *stack_A, t_stack *stack_B)
{
	dbl_listfree(&(stack_A->list));
	dbl_listfree(&(stack_B->list));
}

void	ft_error_lstfree(t_stack *stack_A, t_stack *stack_B)
{
	push_swap_lstfree(stack_A, stack_B);
	ft_error();
}
