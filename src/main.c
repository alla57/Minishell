/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:13:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/18 13:34:49 by alboumed         ###   ########.fr       */
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

	i = 3;
	if (!ft_strncmp(line, "pwd", 3))
	{
		while (ft_isspace(line[i]))
			++i;
		if (line[i] != '\0')
			printf("pwd : too many arguments\n");
		else
			print_abs_path();
		return (1);
	}
	return (0);
}

void	get_command(void)
{
	char	*line;

	get_next_line(STDIN_FILENO, &line);
	if (pwd(line))
		return ;
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
