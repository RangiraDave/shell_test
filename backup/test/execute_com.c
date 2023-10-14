#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/**
 *execute_command - Function to fork a new process & execute the command.
 *@tokens_array: the array with commads to execute
 *Return: Nothing.
 */
int execute_command(char **tokens_array)
{
	int status, i;
	pid_t pid;

	if (!tokens_array || !tokens_array[0])
		return (-1);
	pid = fork();

	if (pid == 0)
	{
		i = 0;
		while (strncmp(tokens_array[i], " ", 1) == 0)
		{
			i++;
		}
		while (strncmp(tokens_array[i], " ", 1) == 0)
		{
			i++;
		}
		if (execve(tokens_array[i], tokens_array, NULL) == -1)
		{
			/*printf("");*/
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error during fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		perror("child process didn't exit");
		return (-1);
	}
	return (1);
}
