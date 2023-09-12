#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
void _echo(char f_path[])
{
	if (f_path == NULL)
		perror("no commands entered");
	else
		printf("%s\n", f_path);
}
