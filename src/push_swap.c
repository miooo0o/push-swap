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

static int  get_malloc_count(char **num_temp);
// get how much malloc size i need


void    parse_input(char **av, int end)
{
	// with ft_split, store value to int * or int[]
	// in this care [ 1 23 "12 39 39" 12 ], how can I parse?
	int i;
	int count;
	char **num_temp;

	i = 0;
	count = 0;
	while (i < end)
	{
		num_temp = ft_split(av[i], ' ');
		count = get_malloc_count();
	}




}

void    input_error_checker(int ac)
{
	if (ac == 1)
		ft_error_basic("blah");
	return ;
}

t_stack *init_input_to_stack_A(int ac, char **av)
{
	// input will parse to parse_input()
	input_error_checker(ac);
	parse_input(av, ac - 1);

}

int main(int ac, char **av)
{
    t_stack *stack_A;
    t_stack *stack_B;

	stack_A = init_input_to_stack_A(ac, av);
}