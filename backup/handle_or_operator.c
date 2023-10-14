#include "shell.h"
#include <string.h>

#define BUFFER_SIZE 1024
/**
 * handle_or_operator - Function to handle ||.
 * @read: Pointer to input string.
 * Return: Nothing to be returned.
 */

void handle_or_operator(char *read)
{
	char **str_or = split_string(read, "||"), **cmd_tokens;
	int status, i = 0;

	if (!str_or)
	{
		perror("error in allocation");
		exit(EXIT_FAILURE);
	}

	while (str_or[i] != NULL)
	{
		cmd_tokens = split_string(str_or[i], " ");
		if (!cmd_tokens)
		{
			printf("No cmd_tokens");
			break;
		}
		status = execute_command(cmd_tokens);
		free(cmd_tokens);
		if (status == 0)
			break;
		i++;
	}

	free(str_or);
}
