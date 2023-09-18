#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * execute_command - Function to fork a new process & execute the command.
 *@tokens_array: it is the array of strings of input commands
 * Return: Nothing.
 */
int execute_command(char **tokens_array)
{
	extern char **environ;
	char **env = environ;
	int status, i;
	pid_t pid;

	if (!tokens_array || !tokens_array[0])
		return (-1);

	pid = fork();

	if (pid == 0)
	{
		i = 0;
		while (strcmp(tokens_array[i], " ") == 0)
			i++;
		while (strcmp(tokens_array[i], "	") == 0)
			i++;
		if (execve(tokens_array[i], tokens_array, env) == -1)
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
