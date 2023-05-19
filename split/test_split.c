#include <unistd.h>
#include <stdlib.h>

char	*ft_do1(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		
		s++;
	}
}

int	ft_strclen(char **s, char c)
{
	int	len;

	len = 0;
	while (1)
	{
		if (**s == '\0')
			break ;
		else if (**s == c)
			break ;
		else if (**s != c)
		{
			len++;
			(*s)++;
		}
	}
	return (len);
}

char	*ft_parser(char *s, char c)
{
	while (1)
	{
		if (*s == '\0')
			break ;
		else if (*s == c)
			s = ft_do1(s, c);
		else if (*s != c)
			ft_do2();
	}
	return (s);
}

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
		{
			while (*s && *s != c)
				s++;
		}
		else if (*s == c)
		{
			while (*s && *s == c)
				s++;
			size++;
		}
	}
	if (size > 0)
		split = (char **)malloc(sizeof(char *) * (size + 1));
	else
		split = NULL;
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
	return (split);
}

char	**ft_split_make(char const *s, char c)
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
			i++;
		}
		else
			s++;
		if (*s == '\0')
			split[i] = NULL;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_size(s, c);
	if (split == NULL)
		return (NULL);
	split = ft_split_malloc(s, c);
	if (split == NULL)
		return (NULL);
	split = ft_split_make(s, c);
	if (split == NULL)
		return (NULL);
	return (split);
}


