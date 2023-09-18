#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
  *list_to_array - it turn the linked list
  *into an arry of strings each containing  a separate command.
  *@head: the head of the list containing the commands
  *Return: a pointer to the array of strings
  */

char **list_to_array(token_t *head)
{
	char **array;
	int count = 0;
	int i;
	token_t *temp = head;

	while (temp)
	{
		count++;
		temp = temp->next;
	}

	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
	{
		perror("Error while allocating memory");
		exit(EXIT_FAILURE);
	}
	temp = head;
	for (i = 0; i < count; i++)
	{
		array[i] = temp->token;
		temp = temp->next;
	}
	array[count] = NULL;
	return (array);
}
