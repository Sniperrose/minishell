#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_echo
{
    int     flag_n;
    int     flag;
    char    *str_echo;
} t_echo;


#endif