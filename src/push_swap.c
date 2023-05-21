#include "push_swap.h"

void ft_error_basic(char *msg);

int main(int ac, char **av)
{
	t_stack stack_A;
	t_stack stack_B;

	if (ac == 1)
		ft_error_basic("blah");
	else
		stack_A = init_input_to_stack_A();

}