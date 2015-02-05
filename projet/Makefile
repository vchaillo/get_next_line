# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/22 08:35:30 by vchaillo          #+#    #+#              #
#    Updated: 2015/01/27 21:07:35 by vchaillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = test_gnl

SRC = get_next_line.c

OBJS = $(SRC:.c=.o)

OBJS_PATH = objs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I /libft/includes/ -c $(SRC)
	@gcc $(FLAGS) -I /libft/includes/ -c main.c
	@gcc -o $(NAME) get_next_line.o main.o -L libft/ -lft
	@mkdir objs/
	@mv $(OBJS) main.o $(OBJS_PATH)
	@echo "\033[32mtest_gnl was created!\033[0m"

norm:
	@echo "\033[32mnorminette...\033[0m"
	@norminette $(SRC) get_next_line.h

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\033[31msuppression main.o et get_next_line.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31msuppression test_gnl\033[0m"

re: fclean all

.PHONY: all norm clean fclean re
