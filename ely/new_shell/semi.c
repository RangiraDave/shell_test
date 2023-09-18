#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
  *handle_semi - it handles the commands when the semicolon is entered
  *@read: the string entered in input
  */
void handle_semi(char *read)
{
	char **str = malloc(BUFFER_SIZE);
	int i = 0;
	char delim = ';';
	char *command_path;

	if (!str)
	{
		perror("error in allocation");
		exit(EXIT_FAILURE);
	}
	if (strchr(read, delim) == NULL)
		return;
	str = split_string(read, ";");

	command_path = find_executable(str[0]);
	str[0] = command_path;

	while (str[i] != NULL)
	{
		execute_command(str);
		i++;
	}
	free(str);
}
