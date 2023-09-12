#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * execute_com - Function to fork a new process & execute the command.
 *
 * Return: Nothing.
 */

int execute_command(char **tokens_array)
{
	int status;
	pid_t pid;

	if (!tokens_array || !tokens_array[0])
		return (-1);
	
	pid = fork();
	
	if (pid == 0)
	{
		if (execve(tokens_array[0], tokens_array, NULL) == -1)
		{
			perror("Error while executing the command");
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
	}
	
	return (1);
}

