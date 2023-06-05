/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:23:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/29 11:44:22 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_split_getsize(char const *s, char c);
int			*ft_split_getlen(char const *s, char c);
char const 	*ft_move_pointer(char const *s, char c, int rev);
//char		**ft_free_strs(char **strs);
char		**ft_free_strs(char **strs, size_t size);

char	**ft_split(char const *s, char c)
{
	int		*len;
	char	**split;
	int		i;
	size_t	split_size;

	split_size = ft_split_getsize(s, c);
	split = ft_calloc(sizeof(char *), split_size + 1);
	if (split == NULL)
		return (NULL);
	len = ft_split_getlen(s, c);
	if (len == NULL)
		return (NULL);
	i = 0;
	while (split && len[i])
	{
		s = ft_move_pointer(s, c, 0);
		split[i] = ft_substr(s, 0, len[i]);
		if (split[i] == NULL)
			return (split = ft_free_strs(split, i));
		s = s + len[i++];
	}
	free(len);
	len = NULL;
	return (split);
}

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
	len = ft_calloc(sizeof(int), size + 1);
	if (len == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
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

/*
char	**ft_free_strs(char **strs)
{
	int		i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}
*/

char	**ft_free_strs(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char const	*ft_move_pointer(char const *s, char c, int rev)
{
	while (*s && (*s == c) == (!rev))
		s++;
	return (s);
}


