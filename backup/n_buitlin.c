#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * builtin - Function to handle builtin commands.
 * @arg_0: Pointer to the first command.
 * @arg_1: Pointer to second argument.
 * @arg_2: Pointer to third argument.
 * Return: 0 for Success and -1 for Failure.
 */

int builtin(char *arg_0, char *arg_1, char *arg_2)
{
	if (strncmp(arg_0, "cd", 2) == 0)
		_cd(arg_1);
	else if (strncmp(arg_0, "pwd", 3) == 0)
		_pwd();
	else if (strncmp(arg_0, "setenv", 6) == 0)
	{
		if (arg_1 != NULL && arg_2 != NULL)
			_setenv(arg_1, arg_2, 1);
	}
	else
		return (-1);
	return (0);
}
