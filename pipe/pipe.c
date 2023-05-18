#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_child(void);
void	ft_parent(void);


int	main(void)
{
	int	pid;
	int	fd[2];
	int	status;

	pipe(fd);
	pid = fork();
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(&status);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ft_child();
	}
	
	return (0);
}


void	ft_child(void)
{
	write(1, "Hello\n", 6);
}

void	ft_parent(void)
{
	char	buf[6];

	read(0, buf, 6);
}

