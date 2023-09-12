#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

char **split_string(char *str, const char *delim);
ssize_t _getline(char *line, ssize_t size);
void _pwd(char f_path[]);
void _cd(char f_path[]);
void _echo(char f_path[]);
#endif
