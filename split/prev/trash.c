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

char	**ft_charpp(char const *s, char c)
{
	char	**split;

	if (size != 0)
	{
		split = (char **)ft_calloc(sizeof(char *), size + 1);
		if (split)
			return (split);
	}
	return (NULL);
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
	return (dup);
}
