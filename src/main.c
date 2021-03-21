/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:13:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/21 14:12:23 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	print_abs_path(void)
{
	char	*path;
	size_t	len;

	len = 50;
	if (!(path = malloc(sizeof(char) * len)))
		return (0);
	while (!getcwd(path, len))
	{
		free(path);
		len *= 2;
		if (!(path = malloc(sizeof(char) * len)))
			return (0);
	}
	ft_putstr_fd(path, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (1);
}

int pwd(char **args)
{
	int i;

	i = 0;
	if (!ft_strncmp(args[0], "pwd", 3))
	{
		if (!args[1])
		{
			print_abs_path();
			return (1);
		}
	}
	return (0);
}

void	extern_cmds(char **args)
{
	char	*bin_path;
	char*	env[]={NULL};
	int		status;

	bin_path = "/bin/";
	bin_path = ft_strjoin(bin_path, args[0]);
	if (fork() > 0)
		waitpid(-1, &status, 0);
	else
	{
		if (execve(bin_path, args, env) == -1)
			printf("%s : command not found\n", args[0]);
	}
	free(bin_path);
	free_multi((void**)args);
}

void my_commands(char **args)
{
	if (pwd(args))
		return ;
	else
		printf("%s : command not found\n", args[0]);
}

void check_cmd(char *cmd)
{
	char	**args;
	char	**my_cmds;
	char	*my_cmd;
	int		i;

	i = 0;
	my_cmd = "echo cd pwd export unset env exit";
	my_cmds = ft_split(my_cmd, ' ');
	args = ft_split(cmd, ' ');
	while (my_cmds[i] && ft_strcmp(args[0], my_cmds[i]))
		++i;
	if (!my_cmds[i])
		extern_cmds(args);
	else
		my_commands(args);
}

void	get_command(void)
{
	char	*line;
	char	**cmds;
	// char	*bin_path;
	// char*	env[]={NULL};
	// int		status;
	int		i;

	i = -1;
	get_next_line(STDIN_FILENO, &line);
	cmds = ft_split(line, ';');
	while (cmds[++i])
	{
		check_cmd(cmds[i]);
	}
}

int main(void)
{
	while (1)
	{
		ft_putstr_fd("$> : ", STDOUT_FILENO);
		get_command();
	}
	return (0);
}
