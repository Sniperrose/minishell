#include "includes/minishell.h"

void    ft_env(char **envp)
{
    while (*envp)
    {
        printf("%s\n", *envp++);
        // *envp++;
    }
}

int is_whitespace(char  c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

char    *ft_getstr(char *line)
{
    int len;
    int i;
    int f_sep;
    char    *str;

    len = 0;
    i = 0;
    f_sep = 0;
    str = NULL;
    while (is_whitespace(*line))
        line++;
    while (line[i] != '\0')
    {
        while (!is_whitespace(line[i]))
        {
            i++;
            len++;
            f_sep = 0;
        }
        if (is_whitespace(line[i]) && f_sep == 0)
        {
            f_sep = 1;
            len++;
        }
        while (is_whitespace(line[i]) && f_sep == 1)
            i++;
    }
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    len = 0;
    while (line[i] != '\0')
    {
        while (!is_whitespace(line[i]))
        {
            str[len] = line[i];
            len++;
            i++;
            f_sep = 0;
        }
        if (is_whitespace(line[i]) && f_sep == 0)
        {
            str[len++] = ' ';
            f_sep = 1;
        }
        while (is_whitespace(line[i]) && f_sep == 1)
            i++;
    }
    str[len] = '\0';
    // printf("%s", str);
    return (str);
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
    }
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