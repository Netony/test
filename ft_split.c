#include <unistd.h>
#include <stdlib.h>

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
	split = (char **)malloc(sizeof(char *) * (size + 1));
	return (split);
}


char	**ft_split_malloc(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	split = ft_size(s, c);
	i = 0;
	while (*s)
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
	return (split);
}


char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split_malloc(s, c);
	while (*s)
	{
		if (!(*s == c))
		{
			j = 0;
			while (!(*s == c || *s == 0))
				split[i][j++] = *(s++);
			split[i][j] = '\0';
			i++;
		}
		else
			s++;
	}
	return (split);
}

