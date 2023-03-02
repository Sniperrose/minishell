#include "includes/minishell.h"

int is_whitespace(char  c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int is_alpha(char  c)
{
    if (c >= 97 && c <= 122)
        return (1);
    return (0);
}

char    *ft_getname(char *str, unsigned int len)
{
    unsigned int i;
    char    *dup_name;

    if (!str || (strlen(str) < len))
        return (NULL);
    dup_name = malloc(sizeof(char) * (len + 1));
    if (!dup_name)
        return (NULL);
    i = 0;
    while (*str && i < len)
    {
        dup_name[i] = *str;
        str++;
        i++;
    }
    dup_name[i] = '\0';
    return (dup_name);
}

void    ft_free_split(char **split, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        free(split[i]);
        i++;
    }
    free (split);
}

char    **ft_copy_env(char  **envp)
{
    char    **split;
    int i;

    if (!envp || !*envp)
        return (NULL);
    i = 0;
    while(envp[i] != NULL)
        i++;
    split = (char **)malloc((i + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    i = 0;
    while (envp[i])
    {
        split[i] = strdup(envp[i]);
        if (!split[i])
        {
            ft_free_split(split, i);
            return (NULL);
        }
        i++;
    }
    split[i] = NULL;
    return (split);
}

int get_size(char *line)
{
    int i;
    int size;

    i = 0;
    size = 0;
    while (line[i])
    {
        if (is_whitespace(line[i]))
        {
            while(is_whitespace(line[i]))
                i++;
            if (line[i] != '\0')
                size++;
        }
        i++;
    }
    return (size);
}

char    *ft_getstr(char  *line, int n)
{
    int i;

    i = 0;
    split = NULL;
    while (line[i] && !(is_whitespace(line[i])))
        i++;
    split = malloc(sizeof(char) * (i + 1));
    if (!split)
        return (NULL);
    i = 0;
    while (!is_whitespace(line[i]))
    {
        split[i] = line[i];
        i++;
    }
    split[i] = '\0';
    *line = line[i];
    if (is_whitespace(*line))
        line++;
    return (line);
}

char    **ft_parser_echo(char *line)
{
    char    **split;
    int     n_sep;
    int     i;

    while (*line && is_whitespace(*line))
        line++;
    if (strlen(line) == 0)
    {
        split = (char **)malloc(2 * sizeof(char *));
        if (!split)
            return (NULL);
        split[0] = strdup("");
        split[1] = NULL;
        return (split);
    }
    n_sep = get_size(line);
    split = (char **)malloc((n_sep + 1) * sizeof(char *));
    if (!split)
        return (NULL);
    i = 0;
    while (i < n_sep)
    {
        split[i] = ft_getstr(line, jusqua_sep(line));
        if (!split[i])
        {
            ft_free_split(split, i);
            return (NULL);
        }
        i++;
    }
    split[i] = NULL;
    return (split);
}

void    *ft_getcmds(t_cmds *test, char *line, char  **envp)
{
    int i;
    char    *tmp;

    while (is_whitespace(*line))
        line++;
    i = 0;
    tmp = NULL;
    while (is_alpha(*(line + i)))
        i++;
    tmp = ft_getname(line, i);
    if (!tmp)
        return (NULL);
    test->name = tmp;
    if (!strcmp(tmp, "env"))
    {
        test->str = ft_copy_env(envp);
        if (!test->str)
            return (NULL);
    }
    else if (!strcmp(tmp, "echo"))
    {
        test->str = ft_parser_echo(line + i);
        if (!test->str)
            return (NULL);
    }
    return (test);
}

void    *exec(t_cmds *command)
{
    int i;

    printf("cmd name: %s\n", command->name);

    i = 0;
    if (command->str)
    {
        while (command->str[i])
        {
            printf("%s\n", command->str[i]);
            // printf("hi err\n");
            i++;
        }
    }
    printf("---test_here---\n");
    return (command);
}