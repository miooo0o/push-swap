#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/* library */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/* define */
# define MAX 1024

typedef struct		s_stack{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct      s_info{
	int num[MAX];
	int malloc_size;
}                   t_info;

/* utility */
void    ft_free_2d(char **target);
void    ft_error_basic(char *msg);
void    ft_error_2d_free(char *msg, char **target);
# endif