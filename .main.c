#include "get_next_line.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd[10];
	char	*txt[] = {"", "tests/empty.txt", "tests/char.txt", "tests/nlx5.txt", "tests/line.txt", \
	"tests/line_nl.txt", "tests/line_nlx2_line.txt", "tests/line_nlx2_line_nl.txt", \
	"tests/sentences.txt", "tests/random.txt"};
	int		i;
	int		j;
	char	*str;

	i = 1;
	str = 0;
	fd[0] = -1;
	while (i <= 9)
	{
		fd[i] = open(txt[i], O_RDONLY);
		i++;
	}
	i = 0;
	printf("\033[1;34mFOR BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
	while (i <= 9)
	{
		j = 1;
		printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
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
	i--;
	printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
	fd[i] = open(txt[i], O_RDONLY);
	printf("	line 1:%s$\n", get_next_line(fd[i]));
	printf("	line 2:%s$\n", get_next_line(fd[i]));
	close(fd[i]);
	printf("> CLosed - Read\n");
	printf("	line 0:%s$\n", get_next_line(fd[i]));
	fd[i] = open(txt[i], O_RDONLY);
	printf("	line 1:%s$\n", get_next_line(fd[i]));
	printf("	line 2:%s$\n", get_next_line(fd[i]));
	close(fd[i]);
	fd[i] = open(txt[i], O_RDONLY);
	printf("> CLosed - Opened - Read\n");
	printf("	line 0:%s$\n", get_next_line(fd[i]));
	printf("... DONE\n\n");

	printf("\033[1;34mEND OF BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
}
