#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define BUFFER_SIZE 1024
/**
  * handle_and_operator - Function to handle &&.
  * @read: The pointer to inputed command.
  * Return: Nothing.
 */

void handle_and_operator(char *read)
{
	char **str_and = split_string(read, "&&"), **cmd_tokens;
	int status, i = 0;
	int debug_i;

	if (!str_and)
	{
		perror("error in allocation");
		exit(EXIT_FAILURE);
	}

	while (str_and[i] != NULL)
	{
		cmd_tokens = split_string(str_and[i], " ");
for (debug_i = 0; cmd_tokens[debug_i] != NULL; debug_i++)
{
    printf("Cmd Token %d: %s\n", debug_i, cmd_tokens[debug_i]);
}

		str_and[i] = trim_whitespace(str_and[i]);
		if (cmd_tokens && cmd_tokens[0])
		{
			status = execute_command(cmd_tokens);
			free(cmd_tokens);
			if (status != 0)
				break;
		}
		i++;
	}
	free(str_and);
}
