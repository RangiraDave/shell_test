#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * read_input - Function to read user's input.
 *
 * Return: Read bytes.
 */

char *read_input()
{
	char *input;
	ssize_t  buffer_size = 1024;
	ssize_t read;
	
	input = malloc(sizeof(input) * sizeof(char));
	if (!input)
	{
		perror("Error while allocating memory for input");
		exit(EXIT_FAILURE);
	}

	read = _getline(input, sizeof(input));

	if (read == -1)
	{
		free(input);
		exit(98);
	}

	if (strncmp(input, "exit", 4) == 0)
	{
		printf("Exit success!\n");
		exit(98);
	}

	return (input);
}
