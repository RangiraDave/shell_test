#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 */

char **split_string(char *str, const char *delim) {
    int count = 0, i = 0, j = 0, start = 0;
    char **tokens = NULL;

/*	if (delim == 0 || !strchr(str, delim[0]))
	{
		tokens = malloc(2 * sizeof(char *));
		if (!tokens)
			exit(1);
		tokens[0] = strdup(str);
		tokens[1] = NULL;
		return (tokens);
	}*/
	/*determining the number of tokens*/
    while (str[i]) {
        if (strchr(delim, str[i])) {
            count++;
            while (strchr(delim, str[i]) && str[i])
		    i++;
	    if (!str[i] && strchr(delim, str[i - 1]))
		    count++;
        } else
		i++;
    }

    tokens = malloc((count + 1) * sizeof(char *));
    if (!tokens) {
        exit(1);
    }

    i = 0;

    /* Token extraction*/
    while (str[i]) {
        if (strchr(delim, str[i]) || !str[i + 1]) {
            if (str[i] && !str[i + 1]) {
                i++;
            }

            tokens[j] = malloc(i - start + 1);
            if (!tokens[j]) {
                exit(1);
            }

            strncpy(tokens[j], &str[start], i - start);
            tokens[j][i - start] = '\0'; /* Null terminatnge token */
            j++; 

            while (strchr(delim, str[i]) && str[i]) {
                i++;
            }
            start = i;
        } else {
            i++;
        }
    }
    tokens[j] = NULL; /* Null terminate the array of tokens*/

    return tokens;
}
