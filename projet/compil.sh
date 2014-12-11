make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -g -I libft/includes/ -c get_next_line.c
gcc -Wall -Wextra -Werror -g -I libft/includes/ -c main.c
gcc -g -o test_gnl get_next_line.o main.o -L libft/ -lft
echo "\033[32mtest_gnl was created\033[0m"
