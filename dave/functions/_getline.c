#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

ssize_t _getline(char *line, ssize_t size)
{
        ssize_t len;
        if (fgets(line, size, stdin) == NULL)
                return (-1);
        else
        {
                len = strlen(line);
                if (len > 0 && line[len - 1] == '\n')
                        line[len - 1] = '\0';
        }
        return (len);
}
