#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
  *list_to_array - it turns a list into an array of strings
  *@head: the head of the strin
  *Return: the pointer to the array
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
