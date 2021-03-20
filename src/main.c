/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:13:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/20 18:12:36 by alboumed         ###   ########.fr       */
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

int pwd(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		++i;
	if (!ft_strncmp(line + i, "pwd", 3))
	{
		i += 3;
		while (ft_isspace(line[i]))
			++i;
		if (ft_isspace(line[i - 1]) || line[i] == '\0')
		{
			print_abs_path();
			return (1);
		}
	}
	return (0);
}

void	get_command(void)
{
	char	*line;
	char	**cmds;
	char	**args;
	char	*bin_path;
	char* env[]={NULL};
	int status;

	bin_path = "/bin";
	get_next_line(STDIN_FILENO, &line);
	cmds = ft_split(line, ";");
	if (cmds[0])
	{
		args = ft_split(cmds[0], ' ');
		args[0];
	}
	if (pwd(line))
		return ;
	else
	{
		// printf("a PID = %d\n", getpid());
		if (fork() > 0)
		{
			waitpid(-1, &status, 0);
		}
		else
		{
			if (execve("/bin/ls", args, env) == -1)
				printf("%s : command not found\n", line);
		}
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
