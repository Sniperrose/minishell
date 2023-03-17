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