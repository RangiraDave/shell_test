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
	char *input;
	token_t *tokens_list = NULL;
	char **tokens_array = NULL; 
	char *command_path;
		
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_user();

		input = read_input();
		if (!input)
			continue;
		//handle_semi(input);
		tokens_list = parse_input(input);
		tokens_array = list_to_array(tokens_list);

		if (tokens_array && tokens_array[0]) 
		{
			if (n_builtin(tokens_array[0], tokens_array[1]) == 0)
				goto end;				
			command_path = find_executable(tokens_array[0]);
			tokens_array[0] = command_path;
			if (command_path)
			{
<<<<<<< HEAD
				execute_command(tokens_array);
				free(command_path);
			}		
			else
				printf("%s: Command not found.\n", tokens_array[0]);
=======
				command_path = find_executable(tokens_array[0]);
				tokens_array[0] = command_path;
				if (command_path)
				{
					execute_command(tokens_array);
					free(command_path);
				}
				else
				printf("%s: Command not found\n", input);
			}
>>>>>>> 4e0f5d1 (Checked with Test suites)
		}
		free_linked_list(tokens_list);
		
		free(tokens_array);
		free(input);
	}

	return (0);

}
