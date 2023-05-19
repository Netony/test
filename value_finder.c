int	main(int argc, char **argv, char **envp)
{
	argv[argc] = 0;
	return (0);
}

char	*find_env(char **envp)
{
	int	i;
	char	**path;

	while (envp[i])
	{
		split = ft_split(envp[i], "=")
		if (0 == ft_strcmp([0], "PATH"))
			path = ft_split();
	}
}

void	**double_free(char **c)
{
	int	i;

	i = 0;
	while (*c)
	{
		free(*c);
		c++;
	}
}
