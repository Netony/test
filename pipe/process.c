#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	ft_exec_ls(void);
void	ft_exec_cat(void);
void	ft_exec_sleep(void);

int	main(void)
{
	int	i;
	int	pfd[2];
	int	ffd[2];

	dup2(open("./infile", O_RDONLY), 0);
	i = 0;
	while (i++ < 5)
	{
		pipe(pfd);
		if (fork() == 0)
		{
			if (i != 5)
			{
				close(pfd[0]);
				dup2(pfd[1], 1);
				if (i == 1)
					ft_exec_ls();
				else
					ft_exec_cat();
			}
			else
			{
				close(pfd[0]);
				dup2(pfd[1], open("./outfile", O_WRONLY | O_CREAT, 777));
				ft_exec_cat();
			}

		}
		close(pfd[1]);
		dup2(pfd[0], 0);
	}
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
