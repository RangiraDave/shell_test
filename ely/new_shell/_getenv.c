#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
  *_getenv - it gets the envirnment being used by the program
  *@name: it is the name of the variable to get
  *Return: NULL
  */

char *_getenv(const char *name)
{
	extern char **environ;
	int i, j;
	char *env_name;
	char *env_value;
	char **token;
	char *copy;

	if (!name || name == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (environ[i] != NULL)
	{
		env_name = environ[i];
		env_value = strchr(environ[i], '=');

		if (env_value != NULL)
		{
			*env_value = '\0';
			env_value++;
			if (strcmp(env_name, name) == 0)
			{
				copy = strdup(env_value);
				token = split_string(copy, ":");
				while (token[j] != NULL)
				{
					free(copy);
					return (token[j]);
					j++;
				}
			}
		}
		i++;
	}
	return (NULL);
}
