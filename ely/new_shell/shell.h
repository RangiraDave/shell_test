#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>

typedef struct token_s
{

	char *token;
	struct token_s *next;
} token_t;

void prompt_user(void);
char *read_input(void);
ssize_t _getline(char *line, ssize_t size);
token_t *parse_input(char *input);
token_t *parse_path(void);
char **split_string(char *str, const char *delim);
char *_getenv(const char *name);
int execute_command(char **tokens_array);
char **list_to_array(token_t *head);
char *find_executable(char *command);
void free_linked_list(token_t *head);
void print_env(void);
void handle_semi(char* read);
int n_builtin(char *arg_0, char *arg_1);
void _cd(char f_path[]);
void _pwd(char f_path[]);

#endif
