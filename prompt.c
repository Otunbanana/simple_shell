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
int i;

for (i = 0; prompt[i] != '\0'; i++)
{
putchar(prompt[i]);
}
if (fgets(line, MAX_LINE, stdin) == NULL)
{
putchar('\n');
exit(0);
}

line[strlen(line) - 1] = '\0';
}
