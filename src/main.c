/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:13:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/18 12:32:23 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void print_abs_path(char *path)
// {
// 	getcwd(path, len);
// 	ft_putstr_fd(path, fd);
// }

int main()
{
	char *line;
	char path[100];
	int fd;
	size_t len;

	fd = 0;
	len = 100;
	ft_putstr_fd("$> : ", fd);
	get_next_line(fd, &line);
	getcwd(path, len);
	ft_putstr_fd(path, fd);
	return (0);
}