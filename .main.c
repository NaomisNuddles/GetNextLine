#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	static char	bla[BUFFER_SIZE + 1];
	int k = open("tests/random.txt", O_RDONLY);
	ssize_t a = read(k, bla, BUFFER_SIZE);
	ssize_t b = read(k, bla, BUFFER_SIZE);
	ssize_t c = read(k, bla, BUFFER_SIZE);
	printf("to fd - %i\na:%ld\nb:%ld\nc:%ld\nstr:%s$\n", k, a, b, c, bla);
	close(k);
	/*int 	fd[11];
	int 	i;
	int		j;
	char	*str;

	i = 0;
	str = 0;
	fd[0] = -1;
	k = open("tests/empty.txt", O_RDONLY);
	fd[1] = k;
	k = open("tests/char.txt", O_RDONLY);
	fd[2] = k;
	k = open("tests/nlx5.txt", O_RDONLY);
	fd[3] = k;
	k = open("tests/line.txt", O_RDONLY);
	fd[4] = k;
	k = open("tests/line_nl.txt", O_RDONLY);
	fd[5] = k;
	k = open("tests/line_nlx2_line.txt", O_RDONLY);
	fd[6] = k;
	k = open("tests/line_nlx2_line_nl.txt", O_RDONLY);
	fd[7] = k;
	k = open("tests/sentences.txt", O_RDONLY);
	fd[8] = k;
	k = open("tests/random.txt", O_RDONLY);
	fd[9] = k;
	fd[10] = -1;

	printf("Testing fd % i ...\n\n", fd[9]);
	printf("	line %.1i:%s$\n", 1, get_next_line(fd[9]));
	l = close(fd[9]);
	printf("	line %.1i:%s$\n", l, get_next_line(fd[9]));
	printf("\033[1;34m\n\nBUFFR_SIZE %i:\n\n\033[0;39m", BUFFER_SIZE);
	while (i <= 10)
	{
		j = 1;
		printf("Testing fd % i ...\n\n", fd[i]);
		str = get_next_line(fd[i]);
		while (str && *str)
		{
			printf("	line %.1i:%s$\n", j, str);
			str = get_next_line(fd[i]);
			j++;
		}
		printf("	line %.1i:%s$\n\n", j, str);
		printf("... DONE\n\n");
		i++;
	}
	printf("\033[1;34mEND OF BUFFER_SIZE %i:\n\n\033[0;39m", BUFFER_SIZE);*/
}