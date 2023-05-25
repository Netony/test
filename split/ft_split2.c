#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_free_strs(char **strs)
{
	while (*strs)
		free(*strs);
}

const char *ft_move_pointer(const char *s, char c, int rev)
{
	while (*s && (*s == cj == (!rev))
		s++;
	return (s);
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
		split = (char **)malloc(sizeof(char *) * (size + 1));
		if (split)
			return (split);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	split = ft_charpp(s, c);
	if (split == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s = ft_move_pointer(s, c, 0);
		else
		{
			split[i] = ft_make_char(s, c);
			if (split[i] == NULL)
				ft_free_strs(split);
			i++;
		}
	}
	split[i] == NULL;
	return (split);
}

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

int	main(void)
{
	char	*s1 = "     HELLO MY NAME IS";
	char	*s2 = "HELLOMYNAME IS    ";
	char	*s3 = "        ";

	printf("%p\n", ft_charpp(s1, ' '));
	printf("%p\n", ft_charpp(s2, ' '));
	printf("%p\n", ft_charpp(s3, ' '));
	/*
	while (*s)
		printf("%d\n", ft_strclen(&s, ' '));
		*/
	return (0);
}
