#include "includes/minishell.h"

t_list *ft_line2list(char *line)
{
    t_list  *new;
    int     i;
    char    *key;
    
    while (is_whitespace(*line))
        line++;
    i = 0;
    key = NULL;
    while (is_alpha(*(line + i)))
        i++;
    key = ft_getname(line, i);
    if (!key)
        return (NULL);
    while (is_whitespace(*(line + i)) || (*(line + i) == '='))
        i++;
    new = create_elm(key, line + i);
    if (!new)
        return (NULL);
    // ft_add2list(cmds, new);
    return (new);
}

int exec(t_list **list, t_list *cmd)
{
    if (!ft_strncmp(cmd->key, "find", 4))
        printf("%s\n", ft_find_elm(list, cmd->val));
    if (!ft_strncmp(cmd->key, "add", 3))
    {
        // t_list *add;

        // add = ft_line2list(cmd->val);
        ft_add2list(list, ft_line2list(cmd->val));
    }
    if (!ft_strncmp(cmd->key, "del", 3))
    {
        ft_delete_elm(list, cmd->val);
    }
    if (!ft_strncmp(cmd->key, "print", 5))
        ft_printlist(list);
    return (0);
}

int main(int argc, char **argv)
{
    t_list  *cmds;
    t_list  *new;
    (void) argv;

    if (argc != 1)
    {
        printf("test argv err!\n");
        return (0);
    }
    char    *line;
    line = readline("gg_test: ");
    cmds = (t_list *)malloc(sizeof(t_list));
    cmds = NULL;
    while (strncmp(line, "exit", 4))
    {
        if (!(new = ft_line2list(line)))
        {
            printf("err: cant get line or cant create new node\n");
            break;
        }
        if (exec(&cmds, new))
        {
            printf ("error in exec\n");
            break;
        }
        free(line);
        line = readline("gg_test: ");
    }
    if (line)
        free(line);
    return (0);
}