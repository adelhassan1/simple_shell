#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_TOKENS 20


int my_exec(const char *pathname, char *const argv[], char *const envp[]);
char *read_line(void);
int main(int argc, char *argv[]);
char **_strtok(char *str);
// int main(void);

char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif