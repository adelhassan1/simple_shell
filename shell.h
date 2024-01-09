#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \n\t\r\a\""
extern char **environ;

void shell_interactive(void);
void shell_no_interactive(void);

char *read_line(void);
char *read_stream(void);
char **parse_string(char *line);
int execute_args(char **args);

int new_process(char **args);

int main(void);

// int own_cd(char **);
// int own_help(char **);
int own_exit(char **);
// int own_env(char **);

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(const char *str);

#endif