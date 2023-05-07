#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int	i;

	argc = 1;
	argv = 0;
	i = 0;
	while (*env)
	{
		printf("[%d]%s\n", i++, *env);
		env++;
	}
}
