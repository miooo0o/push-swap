#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

/* library */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_stack{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct      s_store{
};
# endif