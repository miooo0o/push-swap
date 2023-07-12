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
NAME		=	libdbl.a
INCLUDE		=	-I../../include
SRCS_DIR	=	src/
OBJS_DIR	=	obj/

#executables
AR			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

###


#sources
SRC_FILES	=	$(MAIN) $(EXTRA)

MAIN		=	dbl_add_front dbl_add_back dbl_del dbl_listsize \
				dbl_move_front dbl_move_last dbl_newnode \
				dbl_swap dbl_swap_adjac dbl_swap_with_front dbl_swap_with_last \
				dbl_swap_front_and_last	dbl_utility dbl_listfree
				

SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

###

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
	
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
clean:
			@$(RM) -rf $(OBJS_DIR)
			@#echo "	$(BLUE)$(BOLD)[libdbl]$(RESET) objects files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re