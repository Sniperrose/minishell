#include "includes/minishell.h"

int main    (int argc, char **argv, char **envp)
{
    t_lexer test;
    t_simple_cmds   command;

    if (argc != 1)
    {
        printf ("test arg err!\n");
        return (0);
    }
    char    *line;
    line = readline("test: ");
    while (strcmp(line, "exit"))
    {
        if (!ft_getbuiltin(&test, &command, line))
        {
            printf ("error in getbuilin!\n");
            break;
        }
        if (!exec(command))
        {
            printf ("error in exec\n");
            break;
        }
        free(line);
        line = readline("test: ");
    }
    if (line)
        free(line);
    return (0);
}