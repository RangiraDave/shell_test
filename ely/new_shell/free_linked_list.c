#include "shell.h"

/**
  *free_linked_list - it frees the linked list that stored the commands
  *@head: the head of the list
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
