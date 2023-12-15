#include "main.h"
#include <stdio.h>

/**
* is_env_command - environment command detected
* @command: the eenvironment command
*
* Return: 0
*/

int is_env_command(const char *command)
{
return (strcmp(command, "env") == 0);
}


/**
* print_environment - print the environment
*
* Return: 0
*/

void print_environment(void)
{
char **env_var = environ;
while (*env_var != NULL)
{
char *current = *env_var;
while (*current != '\0')
{
_putchar(*current);
current++;
}

env_var++;
if (*env_var != NULL)
_putchar('\n');
}
}
