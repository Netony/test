#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipefd[2];
	char	*argv1[5] = {"ls", "-al", "/", NULL};
	char	*argv2[5] = {"cat", "-e", NULL};
	int		status;
	
	argv[argc] = 0;
	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		execve("/bin/cat", argv2, envp);
		wait(&status);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		execve("/bin/ls", argv1, envp);
	}

	/*
	while (count < 1)
	{
		if (wait(&status) == -1)
			exit(EXIT_FAILURE);
		count++;
	}
	*/
	printf("HELLO\n");

	return (0);
}
