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
int status;

child_pid = fork();

if (child_pid < 0)
{
perror("fork");
_exit(EXIT_FAILURE);
}

if (child_pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
perror(args[0]);
_exit(EXIT_FAILURE);
}
}
else
{
waitpid(child_pid, &status, 0);

if (WIFEXITED(status))
{
_exit(WEXITSTATUS(status));
}
else if (WIFSIGNALED(status))
{
_exit(128 + WTERMSIG(status));
}
}
}
