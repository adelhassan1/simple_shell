#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int my_exec(const char *pathname, char *const argv[], char *const envp[]);
char *read_line(void);
int main(void);

#endif