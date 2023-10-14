#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * split_string - Function to split string according to delimiter given.
 * @str: String to be splet.
 * @delim: Delimiter to be used.
 * Return: Array of strings.
 */

char **split_string(char *str, const char *delim)
{
	int count = 0, i = 0, j = 0, t = 0, start = 0;
	char **tokens = NULL;

	while (str[i])
	{
		if (strchr(delim, str[i]))
		{
			count++;
			while (strchr(delim, str[i]) && str[i])
				i++;
			if (!str[i] && strchr(delim, str[i - 1]))
				count++;
		}
		else
			i++;
	}
	tokens = malloc((count + 2) * sizeof(char *));
	while (str[t])
	{
		if (strstr(&str[t], delim) == str + t || !str[t + 1])
		{
			if (strlen(delim) > 1 && strstr(&str[t], delim) == str + t)
				t += strlen(delim) - 1;
			if (!strchr(delim, str[t]) && str[t + 1] == '\0')
				t++;
			if ((t - start) > 0)
			{
				tokens[j] = malloc(t - start + 1);
				strncpy(tokens[j], &str[start], t - start);
				tokens[j][t - start] = '\0';
				j++;
			}
			while (strchr(delim, str[t]) && str[t])
				t++;
			start = t;
		}
		else
			t++;
	}
	tokens[j] = NULL;

	return (tokens);
}
