#include "shell.h"
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024
/**
  *find_executable - it create an executable command
  *@command: the entered command
  *Return: NULL on sucess
  */
char *find_executable(char *command)
{
	struct stat st;
	char *path = malloc(BUFFER_SIZE);
	char *exepath = "/bin/";

	if (path == NULL)
	{
		perror("Error while allocation of  memory for path");
		exit(EXIT_FAILURE);
	}
	if (strstr(command, "/bin/") != NULL)
		snprintf(path, BUFFER_SIZE, "%s", command);
	else
		snprintf(path, BUFFER_SIZE, "%s%s", exepath, command);
	if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
	{
		return (path);
	}
	free(path);
	return (NULL);
}
