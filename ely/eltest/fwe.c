#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
	char **argv = NULL;
	/*char *const envp[] = {"PATH", NULL};*/
	pid_t f_pid;
	size_t bytes_read = 0;
	int read_res;
	int status;
	int e_index; 

	while (1)
	{
		printf ("#");
		read_res = getline(&argv, &bytes_read, stdin);
		if (read_res <= 0)
		{
			perror("unknown action to the system");
			free(argv);
			exit(EXIT_FAILURE);
		}
		if (argv[read_res - 1] == '\n')
		
			argv[read_res - 1] = '\0';
		
		f_pid = fork();

		if (f_pid == -1)
		{
			perror("fork error");
		}
		else if (f_pid == 0)
		{		
			e_index = execve("/bin/", &argv, NULL);
			if (e_index == -1)
			{
				perror("unknow command");
				exit(EXIT_FAILURE);
			}	
		}
		else
		{	
			wait(&status);
		}
	}
	free(argv);
	return (0);
}

