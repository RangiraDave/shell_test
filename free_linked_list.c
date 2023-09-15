#include "shell.h"

/**
 */

void free_linked_list(token_t *head)
{
	token_t *current = head;
	token_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current->token);
		free(current);
		current = next_node;
	}
}
