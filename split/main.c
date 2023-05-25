#include "libft.h"

char const *ft_move_pointer(char const *s, char c, int rev);
char	*ft_dup(char const *s, char c);

void	ft_free_strs(char **strs)
{
	while (*strs)
		free(*strs);
}

char	**ft_charpp(char const *s, char c)
{
	int		size;
	char	**split;

	size = 0;
	while (*s)
	{
		if (*s == c)
			s = ft_move_pointer(s, c, 0);
		else
		{
			s = ft_move_pointer(s, c, 1);
			size++;
		}
	}
	if (size != 0)
	{
		split = (char **)ft_calloc(sizeof(char *), size + 1);
		if (split)
			return (split);
	}
	return (NULL);
}

#include <stdio.h>

int	main(void)
{
	const char 	*s = "HEL EO ELJ LEKF L";
	char	c = ' ';
	int		i;
	char	**a;

	i = 0;
	a = ft_charpp(s, c);
	if (a == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			s = ft_move_pointer(s, c, 0);
			i++;
		}
		else
		{
			a[i] = ft_dup(s, c);
			if (a[i] == NULL)
			{
				ft_free_strs(a);
				return (NULL);
			}
			s = ft_move_pointer(s, c, 1);
		}
	}
	return (0);

}

char	*ft_dup(char const *s, char c)
{
	int		size;
	char 	*dup;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	dup = (char *)ft_calloc(sizeof(char), size + 1);
	if (dup)
	{
		if (size + 1 == ft_strlcpy(dup, s - size, (int)(size + 1)))
			return (dup);
	}
	else
		return (NULL);

	return (dup);
}

char const	*ft_move_pointer(char const *s, char c, int rev)
{
	while (*s && (*s == c) == (!rev))
		s++;
	return (s);
}

/*
char	*ft_make_char(char const *s, char c)
{
	char	*temp;
	char	*make;
	int		size;
	int		i;


	temp = ft_move_pointer(s, c, 1);
	size = (int)(temp - s);
	if (size != 0)
		make = (char *)malloc(sizeof(char) * (size + 1));
	if (size == 0 || make == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		make[i] = s[i];
		i++;
	}
	s[i] = '\0';
}
*/
