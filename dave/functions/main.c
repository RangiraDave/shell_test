#include "shell.h"


/**
 * main - Funtion to continuously read and execut commands.
 *
 * Return: Always 0;
 */

int main(void)
{
	char *input;
	token_t *tokens_list = NULL;
	char **tokens_array = NULL, *command_path = NULL;

	while (1)
	{
		prompt_user();

		input = read_input();
		if (!input)
			continue;
		tokens_list = parse_input(input);
		tokens_array = list_to_array(tokens_list);

		/*printf("%s\n%s\n", tokens_list, tokens_array);*/
		if (tokens_array && tokens_array[0]) /*Atlist one cmd*/
		{
			command_path = find_executable(tokens_list, tokens_array[0]);
			tokens_array[0] = command_path;
			if (command_path)
			{
				execute_command(tokens_array);
				free(command_path);
			}
			else
				printf("%s: Command not found.\n", tokens_array[0]);
		}
		
		free_linked_list(tokens_list);
		free(tokens_array);
		free(input);
	}

	return (0);
}
