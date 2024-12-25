#include "get_next_line.h"
# include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("bla.txt", O_RDONLY);
	printf("s1:%s\n", get_next_line(fd));
	printf("s2:%s\n", get_next_line(fd));
	printf("s2:%s\n", get_next_line(fd));
	printf("s2:%s\n", get_next_line(fd));
	close(fd);
	printf("s3:%s\n", get_next_line(fd));
	open("bla.txt", O_RDONLY);
	printf("s4:%s\n", get_next_line(fd));
	printf("s5:%s\n", get_next_line(fd));
}