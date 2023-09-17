#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void _cd(char *arg_1)
{
	if (arg_1 == NULL)
		return;
	if(chdir(arg_1) == -1)
		{
			fprintf(stderr,"./hsh: 1: cd: can't cd to %s\n", arg_1);
		}
}
