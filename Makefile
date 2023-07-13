
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mi■■■■■ <mi■■■■■@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 15:05:22 by mi■■■■■           #+#    #+#              #
#    Updated: 2023/05/21 16:21:20 by mi■■■■■          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# define
NAME		=	push_swap
INCLUDE		=	-I./include

# directory
SRCS_DIR	=	src/
OBJS_DIR	=	obj/
LIB_DIR	=	./lib/libft ./lib/libdbl


# path (.a file)
LIBFT_PATH		=	lib/libft/libft.a
LIBDBL_PATH		=	lib/libdbl/libdbl.a

# all path (all .a file)
LIB_PATH		=	$(LIBFT_PATH) $(LIBDBL_PATH)

# executables
AR			=	ar rcs
RM			=	rm -f
CC			=	cc -g
CFLAGS		=	-Wall -Wextra -Werror

# sources
SRC_FILES	=	0_ft_error 0_opt_step 0_utility \
			1_push_swap \
			2_parsing_data_to_index 3_init_stack 4_divide_stack_by_ratio \
			5_sort_by_hard_coding 5_utility_sort_five 5_utility_sort_four \
			6_group_update 6_sort_loop \
			7_push 7_reverse_rotate 7_rotate 7_swap \
			test

SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

MAKEFLAGS	+= --silent

###

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m
BOLD = \033[1m

###

all:		$(NAME)

$(NAME):	$(OBJS)
			@./bar.sh
			@$(foreach dir,$(LIB_DIR),make -C $(dir);)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) -o $(NAME)


$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) -g $(INCLUDE) -c $< -o $@

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(foreach dir,$(LIB_DIR),make clean -C $(dir);)

fclean:		clean
			@./bar.sh
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIB_PATH)

re:			fclean all

.PHONY:		all clean fclean re