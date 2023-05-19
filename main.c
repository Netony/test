#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*
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
*/

/*
int	main(void)
{
	char	*p;
	int		i;

	printf("Not initialize: %p\n", p);
	i = 0;
	p = (char *)malloc(sizeof(char) * i);
	printf("Malloc Size 0: %p\n", p);
	printf("Size of p: %lu\n", sizeof(p));
	return (0);
}
*/

int	main(void)
{
	char	*hello;
	hello = get_next_line(0);
	printf("%s", hello);

}
