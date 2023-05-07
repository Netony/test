#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	**ft_split(char const *s, char c);
int		ft_split_size(char const *s, char c);
int		ft_valid_size(int *arr);
int		*ft_split_lens(char const *s, char c, int size);
void	ft_free(char **p, int j);

int	ft_valid_size(int *arr)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (arr[i] != -1)
	{
		if (arr[i] != 0)
			size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i_size;
	int		*j_sizes;
	int		i;
	int		j;

	i_size = ft_split_size(s, c);
	j_sizes = ft_split_lens(s, c, i_size);
	split = (char **)malloc(sizeof(char *) * (ft_valid_size(j_sizes) + 1));
	i = 0;
	while (i < i_size)
	{
		if (j_sizes[i] == 0)
			s++;
		else
		{
			split[i] = (char *)malloc(sizeof(char) * (j_sizes[i] + 1));
			j = 0;
			while (*s != c)
			{
				split[i][j++] = *(s++);
				split[i][j] = '\0';
			}
		}
		i++;
	}
	split[i] = 0;
	return (split);
}

int	ft_split_size(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			size++;
		i++;
	}
	return (size + 1);
}



int		*ft_split_lens(char const *s, char c, int size)
{
	int	len;
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * (size + 1));
	while (*s)
	{
		if (*s == c)
		{
			array[i++] = len;
			len = 0;
		}
		else
			len++;
		s++;
	}
	array[i++] = len;
	array[i] = -1;
	return (array);
}

void	ft_print_array(int *a)
{
	int	i;

	i = 0;
	while (*a != -1)
		printf("[%d]: %d\n", i++, *(a++));
}


int	main(void)
{
	int	size;
	int	*arr;

	size = ft_split_size("Hello..My.Name.Is.DAJEON", '.');
	arr = ft_split_lens("Hello..My.Name.Is.DAJEON", '.', size);
	ft_print_array(arr);
	printf("actual_size: %d\n", size);
	printf("valid_size: %d\n", ft_valid_size(arr));
	ft_print(ft_split("Hello..My.Name.Is.DAJEON", '.'));
}

/*
void	ft_free(char **p, int j)
{
	int	i;
	
	i = 0;
	while (i < j)
	{
		free(p[i]);
	}
}
*/
