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

char    *ft_getline(char *line, int size)
{
    int i;
    char    *str;

    if (!line)
        return (NULL);
    str = malloc(sizeof(char) * (size + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < size)
    {
        str[i] = line[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int ft_getstart(char *line)
{
    int i = 0;

    while (!is_whitespace(line[i]) && line[i])
        i++;
    return (i);
}

char    **ft_parser_echo(char *line)
{
    char    **split;
    int     n_sep;
    int     i;
    int     size;

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
    split = (char **)malloc((n_sep + 2) * sizeof(char *));
    if (!split)
        return (NULL);
    i = 0;
    size = 0;
    // printf("n_sep = %d\n", n_sep);
    while (i <= n_sep)
    {
        size = 0;
        while (is_whitespace(*line) && line)
                line++;
        size = ft_getstart(line);
        // printf("---size %d---\n", start);
        split[i] = ft_getline(line, size);
        if (!split[i])
        {
            ft_free_split(split, i);
            return (NULL);
        }
        if (i < n_sep)
            line += size;
        // printf("line: %s| split[%d]: %s|\n", line, i, split[i]);
        i++;
    }
    split[i] = NULL;
    return (split);
}

char    **ft_getpath(char *line)
{
    char    **split;

    while (*line && is_whitespace(*line))
        line++;
    split = (char **)malloc(2 * sizeof(char *));
    if (!split)
            return (NULL);
    if (strlen(line) == 0)
        split[0] = strdup("");
    else
        split[0] = strdup(line);
    split[1] = NULL;
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
    // else if (!strcmp(tmp, "echo"))
    else
    {
        test->str = ft_parser_echo(line + i);
        if (!test->str)
            return (NULL);
    }
    // else
    // {
    //     test->str = ft_getpath(line + i);
    //     if (!test->str)
    //         return (NULL); 
    // }
    return (test);
}

// void    *exec(t_cmds *command)
// {
//     int i;

//     printf("cmd name: %s\n", command->name);

//     i = 0;
//     if (command->str)
//     {
//         while (command->str[i])
//         {
//             printf("%s\n", command->str[i]);
//             // printf("hi err\n");
//             i++;
//         }
//     }
//     printf("---test_here---\n");
//     return (command);
// }