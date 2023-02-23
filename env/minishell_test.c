#include "includes/minishell.h"

void    ft_env(char **envp)
{
    int i;

    i = 0;
    
    while (*envp)
    {


    }
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
        else
            printf("im not ready for this O.o\n");
        line = readline("test: ");
    }
    return (0);
}