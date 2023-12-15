#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_LINE 256
#define MAX_ARGS 256

extern char *prompt;
extern char **environ;

int main(void);
void read_command(char *line);
void execute_command(char *line);

int is_exit_command(const char *command);
void exit_shell(void);

int is_env_command(const char *command);
void print_environment(void);

void execute_with_fork(char **args);

int _strlen(char *s);
int _putchar(char c);


#endif
