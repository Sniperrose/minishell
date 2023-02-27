#include "includes/minishell.h"

void    ft_env(char **envp)
{
    while (*envp)
    {
        printf("%s\n", *envp++);
        // *envp++;
    }
}

char    *ft_getstr(char *line)
{
    int len;
    int i;
    char    *str;

    len = 0;
    i = 0;
    while (is_whitespace(*line))
        line++;
    while (line[i] != '\0')
    {
        while (!is_whitespace(line[i]))
        {
            len++
        }
    }
    return (str);
}

int is_whitespace(char  c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

void    ft_echo(char *line)
{
    int flag_n;
    char    *str_echo;

    flag_n = 0;
    str_echo = NULL;
    while (is_whitespace(*line))
        line++;
    if (*line == '-' && *(line + 1) == 'n' && is_whitespace(*(line + 2)))
    {
        flag_n = 1;
        line = line + 3;
    }
    str_echo = ft_getstr(line);
    printf("%s", str_echo);
    if (flag_n == 0)
        printf("\n");
    return;
}

int main    (int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    if (argc != 1) 
    {
        printf ("test\n");
        return (1);
    }d
    char    *line;
    line = readline("test: ");
    while (strcmp(line, "exit"))
    {
        if (!strcmp(line, "env"))
            ft_env(envp);
        else if (!strncmp(line, "echo", 4))
        {
            ft_echo(line + 4);
        }
        else
            printf("im not ready for this O.o\n");
        free(line);
        line = readline("test: ");
    }
    if (line)
        free(line);
    return (0);
}