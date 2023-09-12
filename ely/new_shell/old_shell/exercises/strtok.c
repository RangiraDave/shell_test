#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char str[100] = "why, I am, the best, at everything";
	const char del [3] = ",";
	char *broken;

	broken = strtok(str, del); 

	while (broken != NULL)
	{
		printf("%s", broken);
		broken = strtok(NULL, del);
	}
	return (0);
}
