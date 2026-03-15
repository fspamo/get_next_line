#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
