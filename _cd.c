#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void _cd(char f_path[])
{
	if(chdir(f_path) == -1)
		{
			perror("the directory doesn't exist");
		}
}
