#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
void _echo(char f_path[])
{
	if (f_path == NULL)
		perror("no commands entered");
	else
		printf("%s ", f_path);
}
