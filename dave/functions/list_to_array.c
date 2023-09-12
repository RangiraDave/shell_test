#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 */

char **list_to_array(token_t *head)
{
	char **array;
	int count = 0, i = 0;
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

	for (i = 0; temp != NULL; i++)
	{
		array[i] = temp->token;
		temp = temp->next;
	}
	array[i] = NULL;

	return (array);
}
