#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * _pwd - Function to print current working directory.
 * Return: Nothing
 */

void _pwd(void)
{
	char *buf;
	size_t size = 1024;

	buf = malloc((size + 1) * sizeof(char));
	if (getcwd(buf, size) != NULL)
		printf("%s\n", buf);
	else
		perror("pwd failed");
	free(buf);
}
