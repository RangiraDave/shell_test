#include "shell.h"
#include <stdlib.h>

void free_string_array(char **array)
{
    int i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
