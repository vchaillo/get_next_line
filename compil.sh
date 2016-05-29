make -C libft/ fclean
make -C libft/
gcc -Wall -Wextra -Werror -g -I libft/include/ -c src/get_next_line.c
gcc -Wall -Wextra -Werror -g -I libft/include/ -c src/main.c
gcc -g -o test_gnl get_next_line.o main.o -L libft/ -lft
rm -f get_next_line.o main.o
echo "\033[32mtest_gnl was created\033[0m"
