#include "main.h"

/**
* main - Main entry point function
*
* Return: 0 on success
*/

int main(void)
{
char line[MAX_LINE];

while (1)
{
read_command(line);
if (_strlen(line) == 0)
{
continue;
}
if (is_exit_command(line))
{
exit_shell();
}
else if (is_env_command(line))
{
print_environment();
}
else
{
execute_command(line);
}
}
return (0);
}
