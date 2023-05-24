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
LAST_DIR	=	./lib/ft_printf

# path (.a file)
LIBFT_PATH		=	lib/libft/libft.a
PRINTF_PATH		=	lib/ft_printf/libftprintf.a

# all path (all .a file)
LIB_PATH		=	$(LIBFT_PATH) $(PRINTF_PATH)

# executables
AR			=	ar rcs
RM			=	rm -f
CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror

###

GREEN	= \033[0;32m
BLUE	= \033[0;34m
RESET	= \033[0m
BOLD	= \033[1m
WHITE	= \033[37m

###

# sources
SRC_FILES	=	push_swap

SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LAST_DIR) 
			@echo "- $(BOLD)Compiling$(RESET) $(NAME)\n"	
			$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) -o $(NAME)
			@echo "	$(GREEN)$(BOLD)[push swap]$(RESET) $(WHITE)compiled!$(RESET)"	

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@echo -n "["
			@echo -n $$(expr $$(echo "$$(ls -1 $(OBJS_DIR) | wc -l) * 100 / $$(echo "$(SRC_FILES)" | wc -w)" | bc) / 1)
			@echo "%] $(GREEN)Building push swap $@$(RESET)"
			$(CC) -g $(INCLUDE) -c $< -o $@

clean:
			$(RM) -rf $(OBJS_DIR)
			@make clean -C $(LAST_DIR)
			@echo "	$(BLUE)$(BOLD)[push swap]$(RESET) objects files $(BLUE)cleaned$(RESET)!"

fclean:		clean
			$(RM) -f $(NAME)
			@$(RM) -f $(LIB_PATH) 
			@echo "	$(BLUE)$(BOLD)[ALL PATH]$(RESET) executable files $(BLUE)cleaned$(RESET)!"

re:			fclean all
			@echo "	$(GREEN)$(BOLD)[push swap]$(RESET) $(BOLD)cleaned and rebuilt everything$(RESET)!"

.PHONY:		all clean fclean re