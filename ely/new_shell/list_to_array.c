#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 */

char **list_to_array(token_t *head)
{
	char **array;
	int count = 0;
	int i;
	token_t *temp = head;
/*	int t;*/

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
	/*for (t = 0; array[t] != NULL; t++)
		printf("this the contents of the array:%s\n", array[t]);*/

	return (array);
}
