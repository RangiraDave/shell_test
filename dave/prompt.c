#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 */

int main()
{
	char *input = NULL;
	size_t len;
	ssize_t read;
	pid_t pid;
	int status, i;
	char *argv[BUFFER_SIZE];
	char **tokens;
	char *newline;

	while (1)
	{
		printf("#cisfun$ ");
		
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			printf("\n");
			break;
		}
		if (strncmp(input, "exit", 4) == 0)
		{
			printf("Exit success!\n");
			break;
		}

		newline = strchr(input, '\n');
		if (newline)
			*newline = '\0';

		tokens = split_string(input, " ");
		for (i = 0; tokens[i] != NULL; i++)
			argv[i] = tokens[i];
		argv[i] = NULL;
		pid = fork();
		if (pid == -1)
                {
                        perror("Error While forking ");
                        return (1);
                }
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error while Executing");
				return (1);
			}
		}
		else
			wait(&status);
	}

	free(input);

	return (0);
}
