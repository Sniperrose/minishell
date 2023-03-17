#include "includes/minishell.h"

void    ft_printlist(t_list **list)
{
    t_list  *tmp;

    if (!list || !*list)
    {
        printf ("list empty!\n");
        return;
    }
    tmp = *list;
    while (tmp->next != NULL)
    {
        printf("%s=%s\n", tmp->key, tmp->val);
        tmp = tmp->next;
    }
}