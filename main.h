#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int _pormpt(char *lineptr, size_t n);
int _exec(const char *pathname, char *const argv[], char *const envp[]);
int main(int argc, char *argv[]);

#endif