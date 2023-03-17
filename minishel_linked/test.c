#include "includes/minishell.h"

void    ft_add2list(t_list **list, t_list *n_elm)
{
    // if (!*list)
    // {
    //     *list = n_elm;
    //     return ;
    // }
    if (!n_elm) 
        return ;
    if (*list)
        n_elm->next = *list;
    *list = n_elm;
}

t_list  *create_elm(char *key, char *val)
{
    t_list  *new_lst;

    new_lst = (t_list *)malloc(sizeof(t_list));
    if (!new_lst)
        return (NULL);
    if (!key || !val)
        return (NULL);
    new_lst->key = ft_strdup(key);
    if (!new_lst->key)
        return (NULL);
    new_lst->val = ft_strdup(val);
    if (!new_lst->val)
        return (NULL);
    new_lst->next = NULL;
    return (new_lst);
}

char    *ft_find_elm(t_list **list, char *key)
{
    t_list  *tmp;

    if (!list || !*list)
        return (NULL);
    tmp = *list;
    while (tmp->next != NULL)
    {
        if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
            return (ft_strdup(tmp->val));
        tmp = tmp->next;
    }
    return (NULL);
}

void    ft_del_elm(t_list *elm)
{
    if (!elm)
        return ;
    if (elm->key)
        free(elm->key);
    if (elm->val)
        free (elm->val);
}

void    ft_delete_elm(t_list **list, char *key)
{
    t_list  *tmp;
    // t_list  *new;
    int     i;

    if (!list || !*list || !key)
    {
        printf("err: no list or key is null\n");
        return;
    }
    tmp = *list;
    if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0) //1st elm del
    {
        ft_del_elm(tmp);
        *list = tmp->next;
        return; 
    }
    i = 0;
    while (ft_strncmp(tmp->key, key, ft_strlen(key)) && tmp->next != NULL)
    {
        tmp = tmp->next;
        i++;
    }
    ft_del_elm(tmp);
    tmp = tmp->next;
    // new = *list;
    // while (i-- > 0)
    //     new = new->next;
    // new = tmp;
    
    ft_del_elm(tmp);
    *list = tmp->next;
    printf("del test here!\nlist:\n");
    ft_printlist(list);
    printf("tmp:\n");
    ft_printlist(&tmp);
}

// void    ft_delete_elm(t_list **list, char *key)
// {
//     t_list  *tmp;
//     int     i;

//     if (!list || !*list || !key)
//         return;
//     tmp = *list;
//     i = 0;
//     while (tmp->next != NULL)
//     {
//         if (ft_strncmp(tmp->key, key, ft_strlen(key)) == 0)
//         {
//             free(tmp->key);
//             free(tmp->val);
//             tmp = tmp->next;
//             break;
//         }
//         i++;
//         tmp = tmp->next;
//     }
//     while (/* condition */)
//     {
//         /* code */
//     }
    

// }