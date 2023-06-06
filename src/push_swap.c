/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:16:05 by minakim           #+#    #+#             */
/*   Updated: 2023/06/06 23:27:09 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_isnumber_str(char *string)
{
	int i;
	i = -1;
	while (string[++i] != '\0')
	{
		if (string[0] == '-' || string[0] == '+')
			i++;
		if (ft_isalnum(string[i]) != 1)
			return (0);
	}
	return (1);
}

int     get_malloc_size(char **num_temp)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (num_temp[++i] != NULL)
	{
		ft_printf("%s", num_temp[i]);
		if (ft_isnumber_str(num_temp[i]) == FALSE)
			ft_error_2d_free("oops", num_temp);
		count++;
	}
	return (count);
}

int	is_contains_trigger(char const *str, char trigger)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == trigger)
			return (1);
	}
	return (0);
}


// TODO : parse_input 왜인지는 모르겠는데 이상하게 만들어놔서 지우고 새로 해야함
void	parse_input(int ac, char** av, t_stack *stack_A);
/* ac, av 적절하게 파싱
 * 1. 각 인풋이 적절한 형태를 띄고 있는지 확인 한 뒤
 * 2. 옳은 형태라면 stack->num에 저장
 * 3. 아니라면 에러 메세지 반환.
 * */


void	init_new_stack(t_stack **stack_ptr)
{
	t_doubly	*new_node;
	t_doubly	*head_node;
	t_stack		*stack;
	int 		i;

	stack = *stack_ptr;
	i = -1;
	head_node = NULL;
	while (++i < stack->total_size)
	{
		new_node = dbl_newnode((int *)&stack->num[i]);
		dbl_add_back(stack->list, &new_node);
		if (i == 0 && head_node == NULL)
			head_node = new_node;
	}
	if (stack->list->head != head_node || stack->list->last != new_node)
		ft_error_basic("I should free list");
	*stack_ptr = stack;
	ft_printf("Stack A is finished set up.");
}


void	init_input_to_stack_A(int ac, char **av, t_stack *stack_A)
{
	// input will parse to parse_input()
	if (ac < 2)
		ft_error_basic("input number");
	parse_input(ac, av, stack_A);
	init_new_stack(stack_A);
}


int main(int ac, char **av)
{
   	t_stack stack_A;
    t_stack stack_B;

	int i;
	i = 0;

	t_doubly *test = (t_doubly *) malloc(sizeof(t_doubly));
	init_input_to_stack_A(ac, av, &stack_A);
	while (stack_A.total_size > i)
	{
		test->data = stack_A.list->head->data;
		ft_printf("Data at head of stack_A: %d\n", *(int*)test->data);
		// you need to move to the next node in the list
		stack_A.list->head = stack_A.list->head->next;
		i++;
	}

	// Free the allocated memory
	free(test);
}
