#include "includes/minishell.h"

void    ft_env(char **envp)
{
    while (*envp)
    {
        printf("%s\n", *envp);
        *envp++;
    }
}

void    ft_echo(char *line)
{
    if (strlen(line) == 4)
        printf("\n");
    else
        printf("im working on echo!\n");
}

int main    (int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    if (argc != 1) 
    {
        printf ("test\n");
        return (1);
    }
    char    *line;

    line = readline("test: ");
    while (strcmp(line, "exit"))
    {
        if (!strcmp(line, "env"))
            ft_env(envp);
        else if (!strncmp(line, "echo", 4))
        {
            ft_echo(line);
            // printf("%s\n", line);
        }
        else
            printf("im not ready for this O.o\n");
        line = readline("test: ");
    }
    return (0);
}