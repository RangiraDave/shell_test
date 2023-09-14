#include "shell.h"
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *find_executable(char *command)
{
	struct stat st;
	char *path = malloc(BUFFER_SIZE);
	char *exepath = "/bin/";
   	 if (path == NULL)
    	{	
        	perror("Error in allocation of  memory for path");
        	exit(EXIT_FAILURE);
    	}

    	/* Making a full path */
    	snprintf(path, BUFFER_SIZE, "%s%s", exepath, command);

    	if (stat(path, &st) == 0 && (st.st_mode & S_IXUSR))
		return path; /* Return full path */
	free(path);
	return NULL; /* If not found, return NULL. */
}

