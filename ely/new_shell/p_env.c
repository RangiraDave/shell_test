#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
extern char **environ;

void print_env()
{
	unsigned int i;

	char **env = environ;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

