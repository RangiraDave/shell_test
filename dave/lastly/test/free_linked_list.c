#include "shell.h"

/**
 * free_linked_list - Function to free any allocated men=mory for node.
 * @head: Pointer to the head of a linked list.
 * Return: Nothing.
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
	current = NULL;
}
