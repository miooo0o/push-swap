/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:04:15 by minakim           #+#    #+#             */
/*   Updated: 2023/06/18 18:01:06 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "libdbl.h"

/* library */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/* define */
# define MAX 1024

/*
typedef struct		s_doubly{
	void            *data;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

typedef struct 		s_lst{
	t_doubly *head;
	t_doubly *last;
}					t_lst; */

typedef struct      s_stack{
	t_lst	list;
	int		total_size;
}                   t_stack;

/* error */
void    ft_free_2d(char **target);
void    ft_error_basic(char *msg);
void    ft_error_2d_free(char *msg, char **target);
void    ft_error_listfree(char *msg, t_lst *list);
void	ft_progress(char *progress, char *msg);

/* utility */
int		ft_isspace(int c);
int		ft_issort(int array[], int size);
int		ft_atoi_pushswap(const char *str);

/* swap */
void	sa(t_stack *stack_A);
void	sb(t_stack *stack_B);
void	ss(t_stack *stack_A, t_stack *stack_B);

/* push */
void	update_stack_size(t_stack *target_stack, int update);
void	dbl_put_top(t_stack **taken, t_stack **put);
void	pa(t_stack *stack_A, t_stack *stack_B);
void	pb(t_stack *stack_A, t_stack *stack_B);

/* rotate */
void	ra(t_stack *stack_A);
void	rb(t_stack *stack_B);
void	rr(t_stack *stack_A, t_stack *stack_B);

/* reverse rotate */
void	rra(t_stack *stack_A);
void	rrb(t_stack *stack_B);
void	rrr(t_stack *stack_A, t_stack *stack_B);


/* test */
void	print_head(t_doubly *head);
void	print_list(t_lst *list);
void	print_stack(t_stack *stack);
# endif