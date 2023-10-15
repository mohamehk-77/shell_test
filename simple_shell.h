#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>

int pprint_prompt();
void start_procss(char *input);
char **_arguments();

#define print_prompt "#cisfun$ "
#define MAXIMUM_INPUT 1024
#endif