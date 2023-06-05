#include <stdio.h>
#include "../libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*a[5] = {"ls"};
	int		fd;

	(void)argc;
	(void)argv;
	(void)a;
	fd = open("infile", O_RDONLY);
	if (fd < 0)
		exit(1);
	dup2(fd, 0);
	execve("/bin/cat", NULL, NULL);
	return (0);
}
