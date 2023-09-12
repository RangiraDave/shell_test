#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 */

int main()
{
	int i, status;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
