#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
extern char **environ;
int builtin(char *arg_0, char *arg_1, char *arg_2)
{
	char **env = environ;
	
	if (strncmp(arg_0,"env", 3) == 0)
		print_env(env);
	else if (strncmp(arg_0, "cd", 2) == 0)
		_cd(arg_1);
	else if (strncmp(arg_0, "pwd", 3) == 0)
		_pwd();
	else if (strncmp(arg_0, "setenv", 6) == 0)
	{
		if (arg_1 != NULL && arg_2 != NULL)
			_setenv(arg_1, arg_2, 1);
	}
	/**else if (strncmp(arg_0, "unsetenv", 8))
			_unset(arg_1);*/
	else
		return (-1);
	return (0);
}
