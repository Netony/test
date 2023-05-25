#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

char	*ft_move_pointer(char *s, char c, int rev)
{
	while (*s && (*s == c) == (!rev))
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
		if (s == c)
			ft_move_pointer(s, c, 1);
		else
		{
			ft_move_pointer(s, c, 0);
			size++;
		}
	}
	if (size != 0)
	{
		split = (char **)malloc(sizeof(char *) * size + 1);
		if (split)
			return (split);
	}
	return (NULL);
}

char	*ft_parser(char const *s, char c)
{
	while (*s)
	{
		if (s == c)
			ft_move_pointer(s, c, 0);
		else
			
	}
}

/*

void	ft_free_double(char **s, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
		free(s[i++]);
}

char	**ft_size(char const *s, char c)
{
	char	**split;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (*s)
	{
		if (!(*s == c))
			s++;
		else if (*s == c)
		{
			while (*s && *s == c)
				s++;
			size++;
		}
	}
	if (size > 0)
	{
		split = (char **)malloc(sizeof(char *) * (size + 1));
		printf("split_size: %d\n", size + 1);
	}
	else
	{
		split = NULL;
		printf("split_size: %d\n", 0);
	}
	printf("split_pointer: %p\n", split);
	return (split);
}


char	**ft_split_malloc(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	split = ft_size(s, c);
	i = 0;
	while (*s && split)
	{
		if (!(*s == c))
		{
			j = 0;
			while (*s && !(*s == c))
			{
				j++;
				s++;
			}
			split[i] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[i] == NULL)
			{
				ft_free_double(split, i);
				split = NULL;
				break ;
			}
			i++;
		}
		else
			s++;
	}
	printf("checkpoint2\n");
	return (split);
}

#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split_malloc(s, c);
	while (*s && split)
	{
		if (!(*s == c))
		{
			j = 0;
			while (!(*s == c || *s == 0))
				split[i][j++] = *(s++);
			split[i][j] = '\0';
			printf("split[%2d]: %15s\n", j, split[i]);
			i++;
		}
		else
			s++;
		if (*s == '\0')
			split[i] = NULL;
	}
	printf("checkpoint3\n");
	return (split);
}

*/
