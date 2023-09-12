#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 */

int main()
{
	pid_t my_pid, new_pid;
	int status;

	printf("Before:%u\n", getpid());
	new_pid = fork();

	if (new_pid == -1)
	{
		perror("Error");
		return (1);
	}
	my_pid = getpid();
	if (new_pid == 0)
	{
		printf("My pid is: %u\n", my_pid);
		sleep(6);
	}
	else
	{
		wait(&status);
		printf("My Parent's pid is: %u\n", my_pid);
	}
	return (0);
}
