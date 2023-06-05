void	ft_perror_file(char *name, char *filename)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putendl_fd(filename, 2);
}
