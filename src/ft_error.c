/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:17:02 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 13:03:11 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free_2d(char **target)
{
	int i;

	i = -1;
	while (target[++i])
		free(target[i]);
	free(target);
}

void    ft_error_basic(char *msg)
{
	ft_printf("[ERROR] : %s\n", msg);
	exit (1);
}

void    ft_error_2d_free(char *msg, char **target)
{
	ft_free_2d(target);
	ft_error_basic(msg);
}

void    ft_error_listfree(char *msg, t_lst *list)
{
	dbl_listfree(list);
	ft_printf("[ERROR] : %s\n", msg);
	exit (1);
}

void	ft_progress(char *progress, char *msg)
{
	ft_printf("[%s] : %s\n", progress, msg);
}