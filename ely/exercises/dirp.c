#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	char *path;
	char *dir;

	path = getenv("PATH");
	if (path != NULL)
	{
		dir = strtok(path, ":");
		while (dir != NULL)
		{
			printf("%s\n", dir);
			dir = strtok(NULL, ":");
		}
	}
	else
	{
		printf("PATH environment not set.\n");
	}
	return (0);
}

