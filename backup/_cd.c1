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
	char *prev, cwd[1024];

	if (!arg_1 || strcmp(arg_1, "~") == 0)
		arg_1 = getenv("HOME");

	if (strncmp(arg_1, "-", 1) == 0)
	{
		prev = getenv("OLDPWD");
		if (prev != NULL)
		{
			if (chdir(prev) != -1)
				printf("%s\n", getcwd(cwd, sizeof(cwd)));
			else
			{
				fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", prev);
				return;
			}
		}
		else
			return;
	}
	else if (chdir(arg_1) == -1)
	{
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", arg_1);
		return;
	}
	setenv("OLDPWD", getenv("PWD"), 1);
	getcwd(cwd, sizeof(cwd));
	setenv("pwd", cwd, 1);
}
