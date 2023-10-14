#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * main - Funtion to continuously read and execut commands.
 *
 * Return: Always 0;
 */

int main(void)
{
	char *input, *command_path, **tokens_array = NULL;
	token_t *tokens_list = NULL;
	size_t tokens_len = array_length(tokens_array);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_user();
		input = read_input();
		if (!input)
			continue;
		handle_logical_operators(input);
		tokens_list = parse_input(input);
		tokens_array = list_to_array(tokens_list);
		if (tokens_array && tokens_array[0])
		{
			if (tokens_len > 2 || strcmp(tokens_array[0], "cd") == 0)
			{
				if (builtin(tokens_array[0], tokens_array[1], tokens_array[2]) == 0)
					goto end;
			}
			else
			{
				command_path = find_executable(tokens_array[0]);
				tokens_array[0] = command_path;
				if (command_path)
				{
					execute_command(tokens_array);
					free(command_path);
				}
				else
					fprintf(stderr, "%s: 1: command not found\n", input);
			}
		}
end:
		free_linked_list(tokens_list);
		free(tokens_array);
		free(input);
	}
	return (0);
}
