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
	char *prev, *home, cwd[1024];

	if (!arg_1 || strcmp(arg_1, "~") == 0)
	{
		home = getenv("HOME");
		if (home)
			chdir(home);
		else
			fprintf(stderr, "./hsh: 1: cd: HOME not set\n");
		return;
	}
	if (strncmp(arg_1, "-", 1) == 0)
	{
		prev = getenv("OLDPWD");
		if (prev != NULL)
		{
			chdir(prev);
			printf("%s\n", getcwd(cwd, sizeof(cwd)));
		}
		else
		{
			fprintf(stderr, "./hsh: 1: cd: OLDPWD not set\n");
			return;
		}
	}
	else if (chdir(arg_1) == -1)
	{
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", arg_1);
		return;
	}
	if (!getcwd(cwd, sizeof(cwd)))
	{
		perror("Error getting current directory");
		return;
	}
	if (setenv("OLDPWD", getenv("PWD"), 1) != 0)
		perror("Error setting OLDPWD");
	if (setenv("PWD", cwd, 1) != 0)
		perror("Error setting PWD");
}
