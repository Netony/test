#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	**hello;

	i = 0;
	hello =  (char **)ft_calloc(sizeof(char **), 9);
	while (i < 9)
	{
		hello[i] = ft_strdup("hello");
		if (hello == NULL)
		{

		}

	i = 0;
	while (i < 9)
	{
		printf("hello[%d]: %s\n", i, hello[i]);
		i++;
	}
	return (0);
}
