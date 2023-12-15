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
int j;

token = strtok(line, " ");
while (token != NULL)
{
args[i] = strdup(token);
if (!args[i])
{
perror("malloc");
for (j = 0; j < i; j++)
{
free(args[j]);
}
exit(1);
}
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
if (!args)
{
perror("malloc");
exit(1);
}

parse_args(line, args);

if (args[0] == NULL) {
free(args);
return;
}


if (access(args[0], X_OK) == -1)
{
char *command_path = malloc(strlen("/bin/") + _strlen(args[0]) + 1);
if (!command_path)
{
perror("malloc");
for (i = 0; i < MAX_ARGS && args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
exit(1);
}
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

return;
}
}
execute_with_fork(args);
}
