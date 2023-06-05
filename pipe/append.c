#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*argv[5] = {"/bin/ls", ".", NULL};
	int		fd;

	fd = open("./infile", O_WRONLY | O_APPEND);
	if (fd > 0)
		dup2(fd, 1);
	execve("/bin/ls", argv, NULL);
}
