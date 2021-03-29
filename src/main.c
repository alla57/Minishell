/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:13:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/29 11:14:39 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
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
	ft_putendl_fd(path, STDOUT_FILENO);
	free(path);
	return (1);
}

int pwd(char **args)
{
	int i;

	i = 0;
	if (!ft_strcasecmp(args[0], "pwd"))
	{
		print_abs_path();
		return (1);
	}
	return (0);
}

char *weak_quote(char *str)
{
	int i;

	i = 0;
}

int get_spec_char(char c)
{
	int		i;
	char	*my_spec_char;

	i = 0;
	my_spec_char = "><|$\'\" ";
	while (c != my_spec_char[i])
		++i;
	if (!my_spec_char[i])
		return (-1);
	return (i);
}

void check_spec_char(char *spec_char)
{
	int i;
	static void (*ft_spec_char[])(void) = {"redir_output", "redir_input", "pipe", "dollar", "strong_quote", "weak_quote", "space"};

	if (!ft_strcmp(spec_char[], ))
}

void my_commands(char **args)
{
	if (pwd(args))
		return ;
	else
		printf("%s : command not found\n", args[0]);
}

void	extern_cmds(char **args)
{
	char	*bin_path;
	char*	env[]={NULL};
	int		status;

	bin_path = "/bin/";
	if (!(bin_path = ft_strjoin(bin_path, args[0])))
		return ;
	if (fork() > 0)
		waitpid(-1, &status, 0);
	else
	{
		if (execve(bin_path, args, env) == -1)
			printf("%s : command not found\n", args[0]);
	}
	free(bin_path);
}

void check_cmd(char *cmd, char **my_cmds)
{
	char	**args;
	int		i;

	i = 0;
	if (!(args = ft_split(cmd, ' ')))
		return ;
	while (my_cmds[i] && ft_strcasecmp(args[0], my_cmds[i]))
		++i;
	if (!my_cmds[i])
		extern_cmds(args);
	else
		my_commands(args);
	free_multi((void**)args);
}

char *find_separator(char *line)
{
	int i;

	i = 0;
	while (line[i] !=)
}

void	get_command(char **my_cmds)
{
	char	*line;
	char	**cmds;
	int		i;

	i = -1;
	get_next_line(STDIN_FILENO, &line);
	find_separator(line);
	cmds = ft_split(line, ';');
	while (cmds[++i])
	{
		check_cmd(cmds[i], my_cmds);
	}
	free(line);
	free_multi((void**)cmds);
}

int main(void)
{
	char	*builtins;
	char	**my_cmds;

	builtins = "echo cd pwd export unset env exit";
	if (!(my_cmds = ft_split(builtins, ' ')))
		return (0);
	while (1)
	{
		ft_putstr_fd("$> : ", STDOUT_FILENO);
		get_command(my_cmds);
	}
	return (0);
}
*/

int main (void)
{
	char			*src;

	src = "3 + 4";
	ft_parsing(src);
	return (0);
}