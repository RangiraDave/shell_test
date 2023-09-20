#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * _echo - Function to handle built in echo.
 * @f_path: String to be displayed.
 * Return: Nothing.
 */

void _echo(char f_path[])
{
	if (f_path == NULL)
		perror("no commands entered");
	else
		printf("%s ", f_path);
}
