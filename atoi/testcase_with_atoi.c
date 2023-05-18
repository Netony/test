#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_atoi(const char *nptr);

void	test(char *s)
{
	char	*alert;

	if (*s == 0)
	{
		printf("=====================================================================\n");
		printf("%32s | %-12s\n", "atoi", "ft_atoi");
		printf("\n");
	}
	else
	{
		if (atoi(s) == ft_atoi(s))
			alert = strdup("✅");
		else
			alert = strdup("❌");
		printf("%32d | %- 32d %s \n", atoi(s), ft_atoi(s), alert); 
	}

}

int	main(int argc, char **argv, char **env)
{
	test("");
	test("  +12434905");
	test("-3551234");
	test("1234");
	test("2147483647");
	test("2147483648");
	test("2147483649");
	test("-2147483648");
	test("-2147483649");
	test("-2147483650");
	test("9223372036854775804");
	test("9223372036854775805");
	test("9223372036854775806");
	test("9223372036854775807");
	test("9223372036854775808");
	test("-9223372036854775809");
	test("-9223372036854775808");
	test("-9223372036854775807");
	test("-9223372036854775806");
	test("-9223372036854775805");
	test("0");

	return (0);
}
