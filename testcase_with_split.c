void	ft_print_array(char **s)
{
	int	i;

	i = 0;
	while (*s != 0)
		printf("[%d]: %s\n", i++, *(s++));
}

int	main(void)
{
	char	*s1 = "ABCDE?FGHIJ?KLMNO?PQRST?UVWXY";
	char	*s2 = "?abcde?fghij?klmno?pqrst?uvwxy";
	char	*s3 = "ABCDE??FGHIJ?KLMNO?PQRST?UVWXY";
	char	*s4 = "ABCDE??FGHIJ?KLMNO?PQRST?UVWXY????";

	ft_print_array(ft_split(s1, '?'));
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split(s2, '?'));
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split(s3, '?'));
	write(1, "-------------------------\n", 26);
	ft_print_array(ft_split(s4, '?'));

	return (0);
}
