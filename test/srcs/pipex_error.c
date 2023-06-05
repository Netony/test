void	ft_perror_file(char *name, char *filename)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": No such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
}

void	ft_perror_command(char *name, char *command)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_putendl_fd(filename, 2);
}
