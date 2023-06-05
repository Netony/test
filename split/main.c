int	*ft_split_len(char const *s, char c);
size_t	ft_split_getsize(char const *s, char c);
char const *ft_move_pointer(char const *s, char c, int rev);
void	ft_free_strs(char **strs);
/*
#include "libft.h"
#include <stdio.h>
void	ft_print_split(char **strs);
void	ft_print_len(int *len);
*/

size_t	ft_split_getsize(char const *s, char c)
{
	int size;

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
	return (size);
}

int	*ft_split_getlen(char const *s, char c)
{
	char	*temp;
	int		*len;
	int		i;
	size_t	size;

	size = ft_split_getsize(s, c);
	if (!size)
		return (NULL);
	len = ft_calloc(sizeof(int), size + 1);
	if (!len)
		return (NULL);
	i = 0;
	while (*s)
	{
		printf("HeRE\n");
		if (*s == c)
			s = ft_move_pointer(s, c, 0);
		else
		{
			temp = (char *)ft_move_pointer(s, c, 1);
			len[i++] = (int)(temp - s);
			s = temp;
		}
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		*len;
	char	**split;
	int		i;

	len = ft_split_getlen(s, c);
	split = ft_calloc(sizeof(char *), ft_split_getsize(s, c) + 1);
	i = 0;
	while (split && len[i])
	{
		s = ft_move_pointer(s, c, 0);
		split[i] = ft_substr(s, 0, len[i]);
		if (!split[i])
		{
			ft_free_strs(split);
			break ;
		}
		s = s + len[i++];
	}
	return (split);
}

void	ft_free_strs(char **strs)
{
	while (*strs)
		free(*strs);
}

/*

#include <stdio.h>

int	main(void)
{
	const char 	*s = "     HEL EO ELJ LEKF L   A ";
	char	c = ' ';
	char	**split;

	ft_print_len(ft_split_getlen(s, c));
	split = ft_split(s, c);
	ft_print_split(split);
}


char const	*ft_move_pointer(char const *s, char c, int rev)
{
	while (*s && (*s == c) == (!rev))
		s++;
	return (s);
}

void	ft_print_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("strs[%d]: %s\n", i, strs[i]);
		i++;
	}
}

void	ft_print_len(int *len)
{
	int	i;

	i = 0;
	while (len[i])
	{
		printf("strs[%d]: %d\n", i, len[i]);
		i++;
	}
}
*/
