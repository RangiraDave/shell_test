#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int n_builtin(char *arg_0, char *arg_1)
{
	if (strncmp(arg_0,"cd", 2) == 0)
		_cd(arg_1);
	else if (strncmp(arg_0, "env", 3) == 0)
		print_env();
	else if (strncmp(arg_0, "pwd", 3) == 0)
		_pwd(arg_0);
	else
		return (0);
}
