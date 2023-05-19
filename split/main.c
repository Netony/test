#include <stdio.h>

int	ft_strclen(char **s, char c)
{ int	len;

	len = 0;
	while (1)
	{
		if (**s == '\0')
			break ;
		else if (**s == c)
		{
			*s += 1;
			break ;
		}
		else if (**s != c)
		{
			*s += 1;
			len++;
		}
	}
	return (len);
}

int	main(void)
{
	char	*s = "HELLO MY NAME IS";

	while (*s)
		printf("%d\n", ft_strclen(&s, ' '));
	return (0);
}
