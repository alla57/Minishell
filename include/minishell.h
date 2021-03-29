/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:06:46 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/29 11:14:32 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./get_next_line.h"
# include "../Libft/libft.h"
/*
typedef struct	s_parsing t_parsing;

struct	s_parsing
{
	int i;
	char c;
	char *str;
	t_parsing *left;
	t_parsing *right;
}		t_parsing;
*/
int ft_parsing(char *src);

#endif