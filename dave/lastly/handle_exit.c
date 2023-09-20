#include "shell.h"
#include <stdio.h>
#include <string.h>

void handle_exit(char *arg1, char *arg)
{
	int status = 0, i;

	if (arg)
	{
		for (i = 0; arg[i] != '\0'; i++)
		{
			if (arg[i] < '0' || arg[i] > '9')
			{
				fprintf(stderr, "./hsh: %s: %s: numeric argument required\n", arg1, arg);
				exit(2);
			}
		}
		status = atoi(arg);
	}
/*	free_string_array(&arg);*/
	exit(status);
}
