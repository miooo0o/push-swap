/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <minakim@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:04:15 by minakim           #+#    #+#             */
/*   Updated: 2023/07/12 18:52:54 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "libdbl.h"

/* library */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/* define */
# define MAX 1024
# define RUN_TOP 1
# define RUN_BOT 0

typedef struct 		s_group{
	int	name;
	int max;
	int mid;
	int min;
	int range;
	int base_range;
	int group_last;
}					t_group;

/**
 * @param total_size is an integer that starts at 0
 * (stack_size >= 1) if element(s) exist in stack.
 * is the current number of elements in the stack
 * It's incremented by 1 when an element is pushed,
 * and decremented by 1 when an element is popped.
 */
typedef struct      s_stack{
	t_lst	list;
	int		stack_size;
	int 	max_total;
	int 	min_total;
}                   t_stack;

typedef struct 		s_info
{
	int		array[MAX];
	int 	index[MAX];
	int 	value[3];
}					t_info;

typedef struct 		s_num
{
	int 	data;
	int 	step_bot;
	int 	step_top;
}					t_num;


/* [0] error */
void	ft_error_lstfree(t_stack *stack_A, t_stack *stack_B);
void	push_swap_lstfree(t_stack *stack_A, t_stack *stack_B);
int		ft_error(void);

/* [0] utility */
int		ft_isspace(int c);
int		ft_issorted(t_stack *stack);
int		check_sorted(t_stack *stack);
int		ft_atoi_from_to(const char *str, int from, int to);

/* [1] push swap & main */

/* [2] parsing_data_to_index */
void	convert_argv_to_int(int ac, char **av, t_info *info);
int		argv_check(char c);
void	change_data_to_index(t_info *info, int length, int value[]);
void	parsing_data_to_index(t_info *info, t_stack *stack);
void	find_max_and_min(int array[], int value[], int length);

/* [3] init stack */
void	init_stack_a_with_arr(t_stack *stack, t_info *info);
int		get_stack_size(t_info *info);
void	init_stack_b(t_stack *stack_A, t_stack *stack_B);
void	initialize_stack(t_stack *stack);

/* [4] divide_stack_by_ratio */
void	divide_stack_by_ratio(t_stack *stack_A, t_stack *stack_B, t_group *target);
void	set_last_group(t_group *target, int size);
void	range_group_to_stack(t_stack *stack_A, t_stack *stack_B, int range);
void	push_till_get_max(t_stack *stack_A, t_stack *stack_B, t_group *group);
int		set_range(int len);

/* [5] sort by hard coding */
void	sort_by_hard_coding(t_stack *stack_A, t_stack *stack_B);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack_A, t_stack *stack_B);
void	sort_five(t_stack *stack_A, t_stack *stack_B);

/* [5] utility sort four */
void	find_min_and_bring_top(t_stack *stack);
int 	navigate_min(t_stack *stack);
int 	navigate_max(t_stack *stack);
int		navigate_sec_min(t_stack *stack_A);

/* [5] utility sort five */
void	find_nums_and_check_step(t_stack *stack, t_num *min, t_num *sec_min);
int		check_special_case(t_stack *stack, int *trigger);
void	if_sec_min_top(t_stack *stack_A, t_stack *stack_B);
void	if_sec_min_bot(t_stack *stack_A, t_stack *stack_B);


/* [6] sort loop */
void	sort_loop(t_stack *stack_A, t_stack *stack_B, t_group *target);
void	sort_in_range(t_stack *stack_A, t_stack *stack_B, t_group *target);
void	take_next_node(t_stack *stack_A, t_stack *stack_B, t_group *target);
int 	count_remaining_nodes(t_stack *stack_A, t_group *target);

/* [6] group update */
void	next_target_group(t_group *target);

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
void	print_all_stack(t_stack *stack_A, t_stack *stack_B);

/* opt step */
void	find_step_from_bot(t_stack *stack, int target, int *step);
void	find_step_from_top(t_stack *stack, int target, int *step);
int		opt_by_step(t_stack *stack, t_num *num);

# endif