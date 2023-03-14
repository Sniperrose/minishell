#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_cmds
{
    char    *name;
    char    **str;
    char    **env;
    int     flag;
} t_cmds;

void    *ft_getcmds(t_cmds *test, char *line, char  **envp);
void    *exec(t_cmds *command);
void    ft_free_split(char **split, int n);
#endif