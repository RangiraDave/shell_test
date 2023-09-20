#include "shell.h"
/**
  *array_length - it calculte the length of the array
  *@array: the array to be calculated
  *Return: the lenght of the function
  */
size_t array_length(char **array)
{
	size_t len = 0;

	while (array && *array++)
		len++;
	return (len);
}

