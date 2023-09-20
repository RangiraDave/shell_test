#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * read_input - Function to read user's input.
 *
 * Return: Read bytes.
 */

char *read_input()
{
	char *input;
	ssize_t read;

	input = malloc(BUFFER_SIZE * sizeof(char));
	if (!input)
	{
		perror("Error while allocating memory for input");
		exit(EXIT_FAILURE);
	}

	read = _getline(input, BUFFER_SIZE);

	if (read == -1)
	{
		free(input);
		exit(0);
	}

/*	if (strncmp(input, "exit", 4) == 0)
	{
		free(input);
		exit(0);
	}*/

	return (input);
}
