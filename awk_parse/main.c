#include <stdio.h>
#include "../libft.h"

void	ft_putstrs_fd(char **strs, int fd);

int	main(int argc, char **argv)
{
	ft_putstrs_fd(argv, 1);
}

void	ft_putstrs_fd(char **strs, int fd)
{
	while (*strs)
		ft_putendl_fd(*(strs++), fd);
}

char	*ft_tok(
