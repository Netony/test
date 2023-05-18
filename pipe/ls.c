#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char	*argv1[5] = {"ls", "-al", ".", NULL};

	if (argc)
		execve("/bin/ls", argv, envp);
	else
		execve("/bin/ls", argv1, envp);
	return (0);
}
