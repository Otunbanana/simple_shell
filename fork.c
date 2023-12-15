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
exit(1);
}

if (child_pid == 0)
{
execve(args[0], args, environ);
perror(args[0]);
exit(1);
}
else
{
waitpid(child_pid, NULL, 0);
}

for (i = 0; i < MAX_ARGS && args[i] != NULL; i++)
{
free(args[i]);
args[i] = NULL;
}
free(args);
}
