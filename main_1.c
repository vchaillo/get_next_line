# include <stdio.h>
# include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include <string.h>
//#include "libft/includes/libft.h"


int main(void)
{
	int fd1;
	char *line;
	int total;
	int total_lines;
	int total_errors;

	line = NULL;
	fd1 = open("test_1.txt", O_RDONLY);
	total_errors = 0;
	total_lines = 0;
	total = 0;
	while (get_next_line(fd1, &line) == 1)
	{
		if (total_lines==0 && strcmp("test de ligne sans retour a la ligne", line) != 0)
		{
			total_errors++;
		}
		total += strlen(line);
		total_lines++;
	}
	if (total_errors == 0 && total_lines == 1 && total == 36)
	{
		printf("\033[0;32mOK");
	}
	else
	{
		printf("\nNombre de caracteres lus : %d\n", total);
		printf("Nombre de caracteres attendus : 36\n");
		printf("Nombre de lignes lues : %d\n", total_lines);
		printf("Nombre de lignes attendues : 1\n");
	}
	close(fd1);
	free (line);
	return (0);
}
