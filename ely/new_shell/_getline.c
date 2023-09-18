#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
  *_getline - it gets the string from the typed input
  *@line:the inputed string in the termiall
  *@size: it is the size if the inputed command
  *Return: the lenght of the input
  */
ssize_t _getline(char *line, ssize_t size)
{
	static ssize_t len;

	if (fgets(line, size, stdin) == NULL)
		return (-1);
	len = strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	line[len - 1] = '\0';

	return (len);
}
