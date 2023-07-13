//#include "push_swap.h"
#include "../include/push_swap.h"

int validate_same_num(int array[], int a)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < a && j > i)
	{
		j = i + 1;
		while (j < a && j != i)
		{
			if (array[i] == array[j])
				ft_error();
			j++;
		}
		i++;
	}
}

int validate_input(char c)
{
	if (ft_isprint(c) && !argv_check(c) && !ft_isspace(c) )
		return (0);
	return (1);
}

int argv_check(char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (ft_isdigit(c))
		return (1);
	return (0);
}

int validate_and_convert(int ac, char **av, int array[], int *a)
{
	int i;
	int	j;
	int from;

	i = 0;
	while (++i < ac && *a < MAX)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!validate_input(av[i][j]))
				ft_error();
			if (argv_check(av[i][j]))
			{
				from = j;
				while (argv_check(av[i][j]))
					j++;
				array[(*a)++] = ft_atoi_from_to(av[i], from, j);
				validate_same_num(array, (*a));
			}
			else
				j++;
		}
	}
	return (*a);
}

void convert_argv_to_int(int ac, char **av, t_info *info)
{
	int a;
	int array[MAX];

	a = 0;
	a = validate_and_convert(ac, av, array, &a);
	if (a < 1)
		ft_error();
	ft_memcpy(info->array, array, a * sizeof(int));
}
