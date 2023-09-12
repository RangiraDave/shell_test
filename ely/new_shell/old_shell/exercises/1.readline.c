#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	size_t bytes_read = 0;
	char *str = NULL;
	int read_bytes;

	printf("please enter a string\n");
	read_bytes = getline(&str, &bytes_read, stdin);
	
	if (read_bytes > 1)
	{
		printf(" you wrote this. \n");
		puts(str);
	}
	else
	{
		perror("getline");
		free(str);
	}
	return (bytes_read);
}
