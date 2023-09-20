#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>

/**
 * _cd - Function to handle built in cd.
 * @arg_1: Represataion of desired directory.
 * Return: Nothing.
 */

void _cd(char *arg_1)
{
	char *prev;

	if (arg_1 == NULL)
		return;
	if (strncmp(arg_1, "-", 1) == 0)
	{
		prev = getenv("OLDPWD");
		if (prev != NULL)
		{
			if (chdir(prev) == -1)
				return;
		}
	}
	if (chdir(arg_1) == -1)
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", arg_1);
}
