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
extern char **environ;
int main()
{
	char input[BUFFER_SIZE];
	char *env[] = {"PATH=/bin:/usr/bin:/usr/local/bin"};
	ssize_t read;
	pid_t pid;
	int status, i, j;
	char *argv[BUFFER_SIZE];
	char **tokens;
	char *newline;

	while (1)
	{
		printf("#cisfun$ ");
		
		read = _getline(input, sizeof(input));
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
		if (strncmp(input, "pwd", 3) == 0)
		{
			_pwd(input);
			goto end;
		}
		newline = strchr(input, '\n');
		if (newline)
			*newline = '\0';

		tokens = split_string(input, " ");
		for (i = 0; tokens[i] != NULL; i++)
			argv[i] = tokens[i];
		argv[i] = NULL;
		
		if (strncmp(argv[0], "cd", 2) == 0)
		{
			_cd(argv[1]);
			goto end;
		}
		//if (strncmp(argv[1], " ", 1) == 0)
				/**_cd();*/

		if (strncmp(argv[0], "echo", 4) == 0)
		{
			j = 1;
			while (argv[j] != NULL)
			{
				_echo(argv[j]);
				j++;
			}
			printf("\n");
			goto end;
		}

		pid = fork();
		if (pid == -1)
                {
                        perror("Error While forking ");
                        return (1);
                }
		if (pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error while Executing");
				return (1);
			}
		}

		else
			end:
			wait(&status);

	}
	return (0);
}
