#include "lib.h"
#include "main.h"

int	main(void)
{
	char	buf[3];
	int		res;

	write(0, "12345", 5);
	res = read(0, buf, 5);
	printf("%s\n", buf);
	return (0);
}

int	ft_dup2_infile(char *filepath, int fd)
{
	int	ffd;

	ffd = open(filepath, O_RDONLY);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}

int	ft_dup2_outfile(char *filepath, int fd)
{
	int	ffd;

	ffd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}

int	ft_dup2_append(char *filepath, int fd)
{
	int	ffd;

	ffd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (ffd > 0)
		dup2(ffd, fd);
	else
	{
		ft_perror_file("pipex", filepath);
		return (-1);
	}
	return (0);
}

int	ft_dup2_here_doc(char *limiter, int fd)
{
	int		ffd;
	char	*join;
	char	*line;

	while (ffd)
	{
		line = get_next_line(0);

	}
	return (0);
}

void	ft_perror_file(char *name, char *filename)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
}

void	ft_perror_command(char *name, char *command)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_putendl_fd(command, 2);
}
