#include "shell.h"

size_t array_length(char **array)
{
	size_t len = 0;
	while(array && *array++)
		len++;
	return (len);
}

