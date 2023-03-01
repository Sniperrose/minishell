#include "includes/minishell.h"

int is_whitespace(char  c)
{
    if (c == 32 || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

int is_alpha(char  c)
{
    if (c == 97 && c <= 122)
        return (1);
    return (0);
}

void    *ft_getbuiltin(t_lexer *test, t_simple_cmds *save_cmd, char *line)
{
    int i;

    while (*line != '\0')
    {
        while (is_whitespace(*line))
            line++;
        i = 0;
        while (is_alpha(line + i))
            i++;
        test->str = strndup(line, i);
        if (!(test->str))
            return (NULL);
    }
    return ((void *) save_cmd);
}