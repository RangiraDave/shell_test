#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/**
 * execute_com - Function to fork a new process & execute the command.
 *
 * Return: Nothing.
 */
extern char **environ;

int execute_command(char **tokens_array)
{
	char **env = environ;
	int status;
	pid_t pid;

	if (!tokens_array || !tokens_array[0])
		return (-1);
	
	pid = fork();
	
	if (pid == 0)
	{
		if (execve(tokens_array[0], tokens_array, env) == -1)
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
			return WEXITSTATUS(status);
		else
			perror("child process didn't exit");
		return (-1);
	}
	
	return (1);
}
