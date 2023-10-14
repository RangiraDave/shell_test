#include "shell.h"
#include <string.h>

/**
 * handle_logical_operators - Fucntion to handle Logical Operators.
 * @read: Pointer to input command.
 * Return: Nothing.
 */

void handle_logical_operators(char *read)
{
	if (strstr(read, "&&"))
		handle_and_operator(read);
	else if (strstr(read, "||"))
		handle_or_operator(read);
	else
	{
		return;
	}
}
