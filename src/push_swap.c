#include "push_swap.h"

void    ft_error_basic(char *msg);

int    ft_isnumber_str(char *string)
{
	int i;
	i = -1;
	while (string[++i] != '\0')
	{
		if (ft_isalnum(string[i]) != 1)
			return (0);
	}
	return (1);
}

void    input_error_checker(int ac)
{
	if (ac == 1)
		ft_error_basic("blah");
	return ;
}

int     get_malloc_size(char **num_temp)
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (num_temp[++i] != NULL)
	{
		if (ft_isnumber_str(num_temp[i]) == FALSE)
			ft_error_basic("your input value include non-digit character.");
		count++;
	}
	return (count);
}

void    parse_input(char **av, int ac)
{
	int i;
	char **num_temp;

	i = -1;
	num_temp = NULL;
	while (++i < ac)
	{
		num_temp = ft_split(av[i], ' ');

	}
}

t_stack *init_input_to_stack_A(int ac, char **av)
{
	// input will parse to parse_input()
	input_error_checker(ac);
	parse_input(av, ac);
}

int main(int ac, char **av)
{
    t_stack *stack_A;
    t_stack *stack_B;

	stack_A = init_input_to_stack_A(ac, av);
}