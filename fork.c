#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
* execute_with_fork - function for fork
* @args: argument passed
*
* Return: 0
*/

void execute_with_fork(char **args)
{
pid_t child_pid;
int i;

child_pid = fork();

if (child_pid < 0)
{
perror("fork");
_exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
execvp(args[0], args);
perror(args[0]);
_exit(EXIT_FAILURE);
}
else
{
waitpid(child_pid, NULL, 0);
}

for (i = 0; i < MAX_ARGS && args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
