/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:17:02 by minakim           #+#    #+#             */
/*   Updated: 2023/05/24 16:17:03 by minakim          ###   ########.fr       */
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
	ft_printf("[ERROR] :");
	ft_printf("%s\n");
	exit (1);
}

void    ft_error_one_2d_free(char *msg, char **target)
{
	ft_free_2d(target);
	ft_error_basic(msg);
}