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
printf("%s\n", *env_var);
env_var++;
}
}
