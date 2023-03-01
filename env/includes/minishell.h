#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_lexer
{
    char    *str;
    t_tokens    token;
    int         i;
    struct s_lexer  *next;
    struct s_lexer  *prev;
}   t_lexer;



typedef struct s_simple_cmds
{
    char    **str;
    int     (*builtin)(t_tools *, struct s_simple_cmds);
    int     num_redirection;
    char    *hd_file_name;
    t_lexer *redirections;
    struct s_simple_cmds    *next;
    struct s_simple_cmds    *prev;
} t_simple_cmds;


#endif