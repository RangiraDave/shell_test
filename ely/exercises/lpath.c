#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	typedef struct node {
		char data;
		struct node *link;
	}n_dir;
	char *path;
	char *dir;
	struct node *h;
		
	path = getenv("PATH");
	dir = strtok(path, ":");
	
	h->data = dir;
	h->link = NULL;
	return (0);
}

