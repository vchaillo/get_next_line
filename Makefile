# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/22 08:35:30 by vchaillo          #+#    #+#              #
#    Updated: 2014/12/09 14:03:08 by valentin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = test_gnl

SRC = get_next_line.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I /libft/includes/ -c $(SRC)
	@gcc $(FLAGS) -I /libft/includes/ -c main.c
	@gcc -o $(NAME) get_next_line.o main.o -L libft/ -lft
	@make clean
	@echo "\033[32mtest_gnl was created!\033[0m"

norm:
	@echo "\033[32mnorminette...\033[0m"
	@norminette $(SRC) get_next_line.h

clean:
	@rm -f $(OBJ) main.o
	@echo "\033[31msuppression main.o et get_next_line.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31msuppression test_gnl\033[0m"

re: fclean all

.PHONY: all norm clean fclean re
