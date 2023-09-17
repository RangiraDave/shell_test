#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int _unset(char *arg_1)
{
	if (arg_1 == NULL || *arg_1 == NULL)
	{
		fprintf(stderr,"variable is already unset.\n");
		return (-1);
	}
	free(*arg_1);
	*arg_1 = NULL;
	return (0);
}

