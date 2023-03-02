#include "includes/minishell.h"

int n_size(char **strstr)
{
	int	i;

	i = 0;
	while(*strstr != NULL)
	{
		i++;
		strstr++;
	}
	return (i);
}

void    ft_free_cmds(t_cmds *cmd)
{
    if (cmd->name)
        free(cmd->name);
    if (cmd->str)
    {
        ft_free_split(cmd->str, n_size(cmd->str));
        cmd->str = NULL;
    }
}

int main    (int argc, char **argv, char **envp)
{
    t_cmds   command;
    (void) argv;

    if (argc != 1)
    {
        printf ("test arg err!\n");
        return (0);
    }
    char    *line;
    line = readline("test: ");
    while (strcmp(line, "exit"))
    {
        if (!ft_getcmds(&command, line, envp))
        {
            printf ("error in getbuilin!\n");
            break;
        }
        if (!exec(&command))
        {
            printf ("error in exec\n");
            break;
        }
        free(line);
            // printf("hi err\n");
        ft_free_cmds(&command);
        line = readline("test: ");
    }
    if (line)
        free(line);
    return (0);
}