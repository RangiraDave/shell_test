#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * _setenv - Function to set an environment variable.
 * @name: Pointer to name of env variable.
 * @value: Pointer to value of env variable.
 * @overwrite: Type of operation.
 * Return: 0 for success and -1 for failure.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int var_len;
	char *var;

	var_len = strlen(name) + strlen(value) + 2;
	var = malloc(var_len);

	if (name == NULL || name[0] == '\0')
	{
		fprintf(stderr, "invald variable");
		return (-1);
	}
	if (overwrite == 0 && getenv(name) != NULL)
		return (0);
	if (var == NULL)
	{
		fprintf(stderr, "no varible detected");
		return (-1);
	}
	snprintf(var, var_len, "%s=%s", name, value);
	if (putenv(var) != 0)
	{
		fprintf(stderr, "unble to set the environment");
		free(var);
		return (-1);
	}
	free(var);
	return (0);
}

