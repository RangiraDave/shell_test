#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int _setenv(const char *name, const char *value, int overwrite)
{
	if (overwrite == 0)
	{
		printf("stop! you are overwriting dude!");
		return (1);
	}
	if (overwrite == 1)
		name = value;
	return (0);
}
