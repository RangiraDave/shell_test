#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
void _pwd(char f_path[])
{
	char *buf;
	size_t size = 1024;

	buf = malloc((size + 1) * sizeof(char));
	if (f_path != NULL)
	{
		if (getcwd(buf, size) != NULL)
			printf("%s\n", buf);
		else
			perror("pwd failed");
	}
	else
		fprintf(stderr, "pwd failed\n");
	free(buf);
}
