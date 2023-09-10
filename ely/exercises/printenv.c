#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main(void)
{

	unsigned int i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s", environ[i]);
	return (0); 
}

