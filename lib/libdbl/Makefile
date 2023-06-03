# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mi■■■■■ <mi■■■■■@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 19:22:56 by minakim           #+#    #+#              #
#    Updated: 2023/04/30 18:06:37 by mi■■■■■          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#standard
NAME		=	libdl.a
INCLUDE		=	-I../../include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/

#executables
AR			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

###

GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m
BOLD = \033[1m
WHITE=\033[37m

###

#sources
SRC_FILES	=	$(MAIN) $(EXTRA)

MAIN		=	dbl_add_front dbl_add_back dbl_del dbl_listsize \
				dbl_move_front dbl_move_last dbl_newnode \
				dbl_isfront dbl_islast dbl_isadjac
				

SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "	$(GREEN)$(BOLD)[libdbl]$(RESET) $(BOLD)compiled!$(RESET)"
	
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@echo -n "["
			@echo -n $$(expr $$(echo "$$(ls -1 $(OBJS_DIR) | wc -l) * 100 / $$(echo "$(SRC_FILES)" | wc -w)" | bc) / 1)
			@echo "%] $(GREEN)Building Libft $@$(RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
			$(RM) -rf $(OBJS_DIR)
			@echo "	$(BLUE)$(BOLD)[libdbl]$(RESET) objects files cleaned!"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "	$(BLUE)$(BOLD)[libdbl]$(RESET) executable files cleaned!"

re:			fclean all
			@echo "	$(GREEN)$(BOLD)[libdbl]$(RESET) $(BOLD)cleaned and rebuilt everything$(RESET)"

.PHONY: all clean fclean re