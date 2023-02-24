#include "includes/minishell.h"

void    ft_env(char **envp)
{
    while (*envp)
    {
        printf("%s\n", *envp);
        *envp++;
    }
}

// void    ft_echo(char *line)
// {
//     if (strlen(line) == 4)
//         printf("\n");
//     else
//         printf("im working on echo!\n");
// }

int ft_getflag(char *line, char *str_echo, int *flag_n)
{
    int i;
    int len;
    char    *tmp;

    i = 0;
    if (line[i] == '-' && line[i + 1] == 'n')
    {
        *flag_n = 1;
        i += 2;
    }
    len = strlen(&line[i]);
    if (len == 0)
    {
        str_echo = strdup("\0");
        return (0);
    }
    tmp = malloc(sizeof(char) * (len + 1));
    if (!tmp)
        return (0);
    int j = 0;
    while (i < len)
    {
        tmp[j++] = line[i++];
    }
    tmp[j] = '\0';
    str_echo = strdup(tmp);
    free (tmp);
    return (0);
}

void    ft_echo(char *line)
{
    int i;
    int flag_prime;
    int flag_n;
    int flag;
    char    *str_echo;

    i = 0;
    flag_prime = 0;
    flag_n = 0;
    while (*line == ' ')
        *line++;
    // printf("%s\n", line);
    flag = ft_getflag(line, str_echo, &flag_n);
    if (flag == 0) //if just normal text
    {
        printf("%s", str_echo);
    }
    else
        printf("im working on this sorry!");
    if (flag_n == 0)
        printf("\n");
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
            // printf("%s\n", line);
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