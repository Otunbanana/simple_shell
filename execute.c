#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
* parse_args - function to Parse the argument
* @line: first argument
* @args: second argument
*
* Return: 0
*/

void parse_args(char *line, char **args)
{
char *token;
int i = 0;

token = strtok(line, " ");
while (token != NULL)
{
args[i] = strdup(token);
i++;
token = strtok(NULL, " ");
}
args[i] = NULL;
}

/**
* execute_command - execute user input
* @line: User input command
*
* Return: 0
*/

void execute_command(char *line)
{
char **args = malloc(sizeof(char *) * MAX_ARGS);
int i;

if (args == NULL)
{
perror("malloc");
exit(1);
}

parse_args(line, args);

if (access(args[0], X_OK) == -1)
{
char *command_path = malloc(strlen("/bin/") + _strlen(args[0]) + 1);
strcpy(command_path, "/bin/");
strcat(command_path, args[0]);

if (access(command_path, X_OK) != -1)
{
args[0] = realloc(args[0], _strlen(command_path) + 1);
strcpy(args[0], command_path);
}
else
{
perror(args[0]);
free(command_path);
for (i = 0; i < MAX_ARGS && args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
return;
}

free(command_path);
}
execute_with_fork(args);
}
