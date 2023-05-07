#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	pid;

	pid = fork();
	if (pid)
		printf("Hello my name is Childs\n");
	else
		printf("Hello my name is Parents\n");
	printf("%d\n", O_RDONLY);
	printf("%d\n", O_WRONLY);
	printf("%d\n", O_RDWR);
	printf("%d\n", O_CREAT);
	return (0);
}
