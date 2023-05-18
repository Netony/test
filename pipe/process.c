#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_exec_ls(void);
void	ft_exec_cat(void);
void	ft_exec_sleep(void);

int	main(void)
{
	int	i;
	int	fds[2];
//	int	status;

	dup2(open("./infile", O_RDONLY), 0);
	i = 0;
	while (i++ < 5)
	{
		pipe(fds);
		if (fork() == 0)
		{
			if (i != 5)
			{
				close(fds[0]);
				dup2(fds[1], 1);
				if (i % 2 == 0)
					ft_exec_sleep();
			}
			ft_exec_cat();
		}
		close(fds[1]);
		dup2(fds[0], 0);
	}

//	dup2(open("./outfile", O_WRONLY | append), 1);
	
}

void	ft_exec_ls(void)
{
	char	*argv[5] = {"/bin/ls", "-al", ".", NULL};
	char	*envp[5] = {NULL};

	execve(argv[0], argv, envp);
}

void	ft_exec_cat(void)
{
	char	*argv[5] = {"/bin/cat", "-e", NULL};
	char	*envp[5] = {NULL};

	execve(argv[0], argv, envp);
}

void	ft_exec_sleep(void)
{
	char	*argv[5] = {"/bin/sleep", "3", NULL};
	char	*envp[5] = {NULL};

	execve(argv[0], argv, envp);
}
