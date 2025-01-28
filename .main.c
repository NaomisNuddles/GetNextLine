#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	/*int fd = open("tests/sentences.txt", O_RDONLY);
	char *line = get_next_line(fd);
	static char buff[BUFFER_SIZE + 1];
	read(open("tests/random.txt", O_RDONLY), buff, BUFFER_SIZE);
	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free (line);*/
	int		fd[18];
	static char	*txt[] = {"", "tests/empty.txt", "tests/char.txt", "tests/nlx5.txt", "tests/line.txt", \
	"tests/line_nl.txt", "tests/line_nlx2_line.txt", "tests/line_nlx2_line_nl.txt", \
	"tests/sentences.txt", "tests/random.txt", "tests/long.txt", "tests/long_nl.txt", "tests/great.txt", \
	"tests/mid.txt", "tests/bad.txt", "tests/limits.txt", "tests/extra.txt", "tests/more.txt"};
	int		i;
	int		j;
	char	*str;

	i = 1;
	str = 0;
	fd[0] = -1;
	while (i <= 17)
	{
		fd[i] = open(txt[i], O_RDONLY);
		printf("fd: %i - at %s\n", fd[i], txt[i]);
		i++;
	}
	i = 0;
	printf("\033[1;34mFOR BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
	while (i <= 17)
	{
		j = 1;
		printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
		str = get_next_line(fd[i]);
		while (str && *str)
		{
			printf("	line %.1i:%s$\n", j, str);
			free(str);
			str = get_next_line(fd[i]);
			j++;
		}
		printf("	line %.1i:%s$\n\n", j, str);
		free(str);
		printf("... DONE\n\n");
		i++;
	}
	i--;

	printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
	fd[i] = open(txt[i], O_RDONLY);
	str = get_next_line(fd[i]);
	printf("	line 1:%s$\n", str);
	free(str);
	str = get_next_line(fd[i]);
	printf("	line 2:%s$\n", str);
	free(str);

	close(fd[i]);
	printf("> CLosed - Read\n");

	str = get_next_line(fd[i]);
	printf("	line 0:%s$\n", str);
	free(str);
	fd[i] = open(txt[i], O_RDONLY);
	str = get_next_line(fd[i]);
	printf("	line 1:%s$\n", str);
	free(str);
	str = get_next_line(fd[i]);
	printf("	line 2:%s$\n", str);
	free(str);

	close(fd[i]);
	fd[i] = open(txt[i], O_RDONLY);
	printf("> CLosed - Opened - Read\n");

	str = get_next_line(fd[i]);
	printf("	line 0:%s$\n", str);
	free(str);
	printf("... DONE\n\n");

	printf("\033[1;34mEND OF BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
}
