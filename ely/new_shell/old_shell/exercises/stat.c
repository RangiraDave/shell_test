#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	const char *f_path;
	struct stat info;
	char *p_copy;


	f_path = getenv("PATH");
	if (argc < 2)
	{
		perror(" I need an argument to procees");
		return (1);
	if (f_path == NULL)
	{
		perror("PATH envi variable not set");
		return (1);
	}
	p_copy = strup(f_path);

	if (p_copy == NULL)
	{
		perror("strup");
		return (1);
	}
	
}
