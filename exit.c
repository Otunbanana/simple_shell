#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_exit_command - Exit command detected
* @command: the exit command
*
* Return: 0
*/

int is_exit_command(const char *command)
{
return (strcmp(command, "exit") == 0);
}

/**
* exit_shell - do exit
*
* Return: 0
*/

void exit_shell(void)
{
exit(0);
}
