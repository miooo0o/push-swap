//
// Created by minakim on 5/24/23.
//

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