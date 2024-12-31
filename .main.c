#include "get_next_line.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int k = open("tests/random.txt", O_RDONLY);

	printf("fd: %d\n", k);
	printf("line1:%s$\n", get_next_line(k));
	close(k);
	printf("line2:%s$\n", get_next_line(k));
	k = open("tests/random.txt", O_RDONLY);
	printf("line1:%s$\n", get_next_line(k));
	/*int 	fd[11];
	int 	i;
	int		j;
	char	*str;

	i = 0;
	str = 0;
	fd[0] = -1;
	fd[1] = open("tests/empty.txt", O_RDONLY);
	fd[2] = open("tests/char.txt", O_RDONLY);
	fd[3] = open("tests/nlx5.txt", O_RDONLY);
	fd[4] = open("tests/line.txt", O_RDONLY);
	fd[5] = open("tests/line_nl.txt", O_RDONLY);
	fd[6] = open("tests/line_nlx2_line.txt", O_RDONLY);
	fd[7] = open("tests/line_nlx2_line_nl.txt", O_RDONLY);
	fd[8] = open("tests/sentences.txt", O_RDONLY);
	fd[9] = open("tests/random.txt", O_RDONLY);
	fd[10] = -1;

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