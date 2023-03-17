#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_list
{
    char            *key;
    char            *val;
    struct s_list   *next;
} t_list;

//utils
size_t  ft_strlen(char  *str);
char    *ft_strdup(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

//ft for linked list
void    ft_add2list(t_list **list, t_list *n_elm);
t_list  *create_elm(char *key, char *val);
char    *ft_find_elm(t_list **list, char *key);
void    ft_delete_elm(t_list **list, char *key);

//for test
void    ft_printlist(t_list **list);
int is_alpha(char  c);
int is_whitespace(char  c);
char    *ft_getname(char *str, unsigned int len);

#endif