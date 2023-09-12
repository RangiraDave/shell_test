#include "shell.h"
#include <stdlib.h>
#include <string.h>

/**
 * parse_input - Funtion to tokenize the read input 
 * and store them in a linked list.
 * Return: Tokens.
 */

token_t *parse_input(char *input)
{
	token_t *new_node = NULL, *head = NULL, *current = NULL;
	char **token;
	unsigned int i = 0;

	token = split_string(input, " \t\n\r\a");
	while (token && token[i] != NULL)
	{
		new_node = malloc(sizeof(token_t));
		if (!new_node)
		{
			printf("Allocation error");
			exit(EXIT_FAILURE);
		}

		new_node->token = strdup(token[i]);
		new_node->next = NULL;

		if (!head)
		{
			head = new_node;
			current = head;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}

/*		token = split_string(NULL, " \t\n\r\a");*/
		i++;
	}
	free(token);
	return (head);
}
