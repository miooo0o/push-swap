/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:04:15 by minakim           #+#    #+#             */
/*   Updated: 2023/07/03 21:44:49 by minakim          ###   ########.fr       */
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
# define Small 0
# define Large 1
# define RUN_TOP 1
# define RUN_BOT 0

/*
typedef struct		s_doubly{
	int				data;
	struct s_doubly	*prev;
	struct s_doubly	*next;
}					t_doubly;

typedef struct 		s_lst{
	t_doubly *head;
	t_doubly *last;
}					t_lst; */

/**
 * @param total_size is an integer that starts at 0
 * (total_size >= 1) if element(s) exist in stack.
 * is the current number of elements in the stack
 * It's incremented by 1 when an element is pushed,
 * and decremented by 1 when an element is popped.
 */
typedef struct      s_stack{
	t_lst	list;
	int		total_size;
}                   t_stack;

typedef struct 		s_info
{
	int		array[MAX];
	int 	index[MAX];
}					t_info;

typedef struct 		s_num
{
	int 	data;
	int 	step_bot;
	int 	step_top;
}					t_num;

/* error */
void    ft_free_2d(char **target);
void    ft_error_basic(char *msg);
void    ft_error_2d_free(char *msg, char **target);
void    ft_error_listfree(char *msg, t_lst *list);
void	ft_progress(char *progress, char *msg);

/* utility */
int		ft_isspace(int c);
int		ft_issorted(t_stack *stack);
int		ft_issort_array(int array[], int size);
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
void	print_all_stack(t_stack *stack_A, t_stack *stack_B);

/* init stack */
void	check_argc(int ac);
void	av_to_array(int ac, char **av, t_info *info);
void	initialize_stack(t_stack *stack);
void	init_stack_a_with_arr(t_stack *stack, t_info *info, int ac);
void	init_stack_b(t_stack *stack_B);

/* sort by hard coding */
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
int 	navigate_min(t_stack *stack);
int 	navigate_max(t_stack *stack);
int		navigate_sec_min(t_stack *stack_A);

/* sort four */
void	sort_four(t_stack *stack_A, t_stack *stack_B);
void	find_step_from_bot(t_stack *stack, int target, int *step);
void	find_step_from_top(t_stack *stack, int target, int *step);
int		opt_by_step(t_stack *stack, t_num *num);
void	find_min_and_bring_top(t_stack *stack);

/* sort five */
void	sort_five(t_stack *stack_A, t_stack *stack_B);
void	find_nums_and_check_step(t_stack *stack, t_num *min, t_num *sec_min);
int		check_special_case(t_stack *stack, int *trigger);
void	if_sec_min_top(t_stack *stack_A, t_stack *stack_B);
void	if_sec_min_bot(t_stack *stack_A, t_stack *stack_B);

# endif