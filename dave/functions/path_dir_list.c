#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * parse_path - function to parse PATH directories and 
 * store them in a linked list.
 * Return: head of the list.
 */

token_t *parse_path(void)
{
	char *path_value = _getenv("PATH"), *path_copy;
	char **token;
	token_t *head = NULL, *current = NULL;
	int i = 0;

	if (!path_value)
		return (NULL);

	path_copy = strdup(path_value);
	if (!path_copy)
	{
		printf("Error while Allocating memory for copy");
		exit(EXIT_FAILURE);
	}

	token = split_string(path_copy, ":");

	while (token && token[i] != NULL)
	{
		printf("%s\n", token[i]);
		token_t *new_dir = malloc(sizeof(token_t));
		if (!new_dir)
		{
			printf("Error while allocating memory for new directory");
			free(path_copy);
			exit(EXIT_FAILURE);
		}

		new_dir->token = strdup(token[i]);
		new_dir->next = NULL;

		if (!head)
		{
			head = new_dir;
			current = head;
		}
		else
		{
			current->next = new_dir;
			current = new_dir;
		}

		token = split_string(NULL, ":");
		i++;
	}

	free(path_copy);

	return (head);
}
