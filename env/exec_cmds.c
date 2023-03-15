#include "includes/minishell.h"

void    *ft_exec_echo(t_cmds *echo)
{
    int i;
    int n_line;
    char    *env;
    int printed;

    i = 0;
    n_line = 1;
    printed = 0;
    if (echo->str[i] && !(strcmp(echo->str[i], "-n")))
    {
        n_line = 0;
        i++;
    }
    env = NULL;
    while (echo->str[i])
    {
        if (!(strcmp(echo->str[i], "*")))
            printed = printf("will print ls!");
        else if (echo->str[i][0] == '$' && echo->str[i][1] != '\0')
        {
            env = getenv(&echo->str[i][1]);
            if (env)
                printed = printf ("%s", env);
        }
        else
        {
            printed = printf("%s", echo->str[i]);
        }
        if (echo->str[i + 1] != NULL && printed != 0)
            printf(" ");
        i++;
    }
    if (n_line == 1)
        printf("\n");
    return(echo);
}

void    *ft_exec_env(t_cmds *env)
{
    int i;

    i = 0;
    while (env->env[i])
    {
        printf("%s\n", env->env[i]);
        i++;
    }
    return (env);
}

void    *ft_exec_pwd(t_cmds *pwd)
{
    //yaj buffer size totsoolohiig oloogui
    char    cwd[1000];

    getcwd(cwd, 1000);
    printf("%s\n", cwd);
    return (pwd);
}

//cd ~go root
//cd .. /go back
//cd wrong path
//cd /tmp or /home go this folder

void    *ft_exec_cd(t_cmds *cd)
{
    int i;

    i = 0;
    while (cd->str[i] != NULL)
        i++;
    if (i != 1)
    {
        printf("cd: too many arguments\n");
        return (cd);
    }
    if (!strcmp(cd->str[0], "") || !strcmp(cd->str[0], "~"))
    {
        chdir(getenv("HOME"));
    }
    else if (chdir(cd->str[0]) == -1)
        printf("cd: %s: No such file or directory\n", cd->str[0]);
    return (cd);
}

void    *ft_err(t_cmds *cmd)
{
    printf("Command '%s' not found, did you mean:\n", cmd->name);
    return (cmd); 
}

void    *exec(t_cmds *command)
{
    if (!strcmp(command->name, ""))
        return (command);
    else if (!strcmp(command->name, "echo"))
        return (ft_exec_echo(command));
    else if (!strcmp(command->name, "env"))
        return (ft_exec_env(command));
    else if (!strcmp(command->name, "pwd"))
        return (ft_exec_pwd(command));
    else if (!strcmp(command->name, "cd"))
        return (ft_exec_cd(command));
    else if (!strcmp(command->name, "export"))
        return (ft_exec_cd(command));
    else if (!strcmp(command->name, "unset"))
        return (ft_exec_cd(command));
    return (ft_err(command));
}