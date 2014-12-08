# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 15:04:37 by vchaillo          #+#    #+#              #
#    Updated: 2014/12/05 16:42:10 by vchaillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRCS = ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c\
	   ft_strclr.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	   ft_strncat.c ft_strcmp.c ft_strstr.c ft_strchr.c ft_isalpha.c\
	   ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c\
	   ft_toupper.c ft_atoi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c\
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c\
	   ft_memmove.c ft_memcmp.c ft_strlcat.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_striter.c ft_striteri.c ft_strmap.c\
	   ft_strmapi.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c\
	   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(SRCS) $(FLAGS) -I includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mlibft.a was created\033[0m"

norm:
	@echo "\033[33mnorminette...\033[0m"
	@norminette $(SRCS) includes/libft.h

rm:
	@rm -f test1
	@rm -f test2
	@rm -f test3

clean:
	@rm -f $(OBJS)
	@echo "\033[31msuppression .o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31msuppression libft.a\033[0m"

re: fclean all

.PHONY: all check test norm rm clean fclean re
