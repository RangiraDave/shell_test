#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
extern char **environ;
void print_env()
{
	char **env = environ;
	unsigned int i;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

