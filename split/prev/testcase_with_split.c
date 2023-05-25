#include <stdio.h>
#include <unistd.h>

char	**ft_split(char const *s, char c);

void	ft_print_array(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (*s != 0)
		printf("[%d]: %s\n", i++, *(s++));
}

int	main(void)
{
	char	*s2 = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";

	ft_split("", ' ');
	ft_print_array(ft_split("", ' '));

	return (0);
}
/*
	char	*s1 = "      split       this for   me  !       ";
	char	*s3 = "ABCDE??FGHIJ?KLMNO?PQRST?UVWXY";
	char	*s4 = "ABCDE??FGHIJ?KLMNO?PQRST?UVWXY????";

	ft_print_array(ft_split(s1, ' '));
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split("", ' '));
	write(1, "-------------------------\n", 26);
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split(s3, '?'));
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split(s4, '?'));
	*/
