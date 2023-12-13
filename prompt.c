#include "main.h"

/**
* read_command - Read user input
* @line: User input command
*
* Return: 0
*/

void read_command(char *line)
{
char *prompt = "#cisfun$ ";
printf("%s", prompt);

if (fgets(line, MAX_LINE, stdin) == NULL)
{
printf("\n");
exit(0);
}

line[strlen(line) - 1] = '\0';
}
