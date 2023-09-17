#include "shell.h"
#include <unistd.h>
#include <string.h>
 
/**
 * main - Funtion to continuously read and execut commands.
 *
 * Return: Always 0;
 */
extern char **environ;
int main(void)
{
	char *input;
	token_t *tokens_list = NULL;
	char **tokens_array = NULL; 
	char *command_path;
	int i = 1;
			
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt_user();

		input = read_input();
		if (!input)
			continue;

		tokens_list = parse_input(input);
		tokens_array = list_to_array(tokens_list);

		if (tokens_array && tokens_array[0]) 
		{
			if (builtin(tokens_array[0], tokens_array[1], tokens_array[2]) == 0)
				goto end;

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
				fprintf(stderr,"%s:1: Command not found\n", input);
				i++;
				return (i);
			}
		}
end:
		/*free_linked_list(tokens_list);*/
		free(tokens_array);
		free(input);	
	}
	return (0);
}
