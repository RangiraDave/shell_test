#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char **environ;
int main(int argc, char **argv, char **env)
{
	printf("environ is: %p\n", (void*)environ);
	printf("env is: %p\n", (void*)env);
	return (0);
}
