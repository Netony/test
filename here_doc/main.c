#include "../libft.h"
#include <stdio.h>
#include <fcntl.h>

/*
int	main(void)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(0);
		if (ft_strncmp(buf, "EOF\n", -1) == 0)
			break ;
		else
			write(1, buf, ft_strlen(buf));
	}
	return (0);
}

*/

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	char	*buf;
	char	*argv2[4] = {"cat", "-e", NULL};
	(void)argc;
	(void)argv;

	pipe(pfd);
	if (fork() == 0)
	{
		close(pfd[0]);
		while (1)
		{
			buf = get_next_line(0);
			if (ft_strncmp(buf, "EOF\n", -1) == 0)
				break ;
			else
				write(pfd[1], buf, ft_strlen(buf));
		}
		return (0);
	}
	close(pfd[1]);
	dup2(pfd[0], 0);
	wait(NULL);
	pipe(pfd);
	if (fork() == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		execve("/bin/cat", argv2, envp);
	}
	else if (fork() == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		execve("/bin/cat", argv2, envp);
	}
	printf("SUCCESS\n");
	return (0);
}

/*
{
	char	*buf;
	int		fd;

	fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (fd)
	{
		buf = get_next_line(0);
		if (1)
			ft_putstr_fd(buf, fd);
		else if (buf == NULL)
		{
			printf("SUCCESS\n");
			free(buf);
			break ;
		}
		free(buf);
	}
	if (fd < 0)
		return (-1);
	close(fd);
	join = ft_strjoin(argv[2], "\n");
	fd = open(".here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd = open(".here_doc", O_RDONLY);
	unlink(".here_doc");
	return (fd);
}
*/
