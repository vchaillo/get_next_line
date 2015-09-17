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

SRC = get_next_line.c

OBJS = $(SRC:.c=.o)

OBJS_PATH = objs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc $(FLAGS) -I /libft/includes/ -c $(SRC)
	@gcc $(FLAGS) -I /libft/includes/ -c main.c
	@gcc -g -o $(NAME) get_next_line.o main.o -L libft/ -lft
	@mkdir objs/
	@mv $(OBJS) main.o $(OBJS_PATH)
	@echo "\033[32mgnl was created!\033[0m"

norm:
	@echo "\033[32mnorminette...\033[0m"
	@norminette $(SRC) get_next_line.h

clean:
	@rm -rf $(OBJS_PATH)
	@echo "\033[31mSuppression main.o et get_next_line.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mSuppression test_gnl\033[0m"

re: fclean all

.PHONY: all norm clean fclean re