#include "main.h"

/**
* read_command - Read user input
* @line: User input command
*
* Return: 0
*/

void read_command(char *line)
{
char *prompt = "$";
int i;

if (isatty(STDIN_FILENO))
{
for (i = 0; prompt[i] != '\0'; i++)
{
_putchar(prompt[i]);
}
}

if (fgets(line, MAX_LINE, stdin) == NULL)
{
exit(0);
}

line[_strlen(line) - 1] = '\0';
}
