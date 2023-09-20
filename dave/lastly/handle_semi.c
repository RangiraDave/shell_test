#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
  *handle_semi - handle semicolon
  *@read: it is the inputed str
  */

void handle_semi(char *read)
{
	char **str = NULL;
	int i = 0;
	char delim = ';';
	char *command_path;

	if (strchr(read, delim) == NULL)
	{
		return;
	}
	else
		str = split_string(read, ";");

	command_path = find_executable(str[0]);
	str[0] = command_path;

	while (str[i] != NULL)
	{
		execute_command(str);
		i++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
