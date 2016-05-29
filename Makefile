# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/22 08:35:30 by vchaillo          #+#    #+#              #
#    Updated: 2015/02/17 08:40:45 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = gnl

CC	=	gcc
CFLAGS	+=	-Wall -Wextra -Werror
RM	=	rm -Rf

SRC = 	main.c \
		get_next_line.c

FILE := $(shell ls libft/libft.a)

LIBFT =	 -Llibft/ -lft

INC	=	-I inc/ -I libft/include/

OBJ	=	$(patsubst %.c, obj/%.o, $(SRC))


all:   $(NAME)
$(NAME): obj $(OBJ)
		
ifneq ($(FILE), libft/libft.a)
	@make -C libft/
endif
	
		@echo "[\033[1;32m******  Creating $(NAME) executable  ******\033[m]"
		@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)

obj/%.o: src/%.c
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
		@echo "[\033[1;32m√\033[m]" $<

obj:
		@mkdir -p obj

clean:
		@echo "[\033[31;1m******  Cleaning object files  ******\033[0m]"
		@$(RM) obj/

fclean:	clean
		@echo "[\033[31;1m******  Cleaning executables  ******\033[0m]"
		@$(RM) $(NAME)

norm:
		@echo "[\033[1;32m******  norminette ...  ******\033[0m]"
		@norminette **/*.[ch]

re: fclean all

.PHONY: all obj clean fclean norm re
