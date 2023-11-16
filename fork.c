#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid = fork();
	
	if (pid == -1)
	{
		printf("Failed to create child process\n");
	}
	else if( pid == 0)
	{
		printf("Child process\n");
	}
	else 
	{
		printf("Parent process\n");
	}
	return 0;
}