#include "shell.h"
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *find_executable(token_t *head, char command[])
{
	struct stat st;
	char *path = malloc(BUFFER_SIZE);
	
	while (head)
	{
		/* Making a full path*/
		snprintf(path, BUFFER_SIZE, "%s/%s", head->token, command);
		if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
			return path; /* Return full path */
		head = head->next; /* Move to the next directory.*/
	}
	free(path);
	return NULL; /* If not found, return NULL.*/
}

