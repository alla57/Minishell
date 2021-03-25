/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:06:46 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/25 17:08:33 by alboumed         ###   ########.fr       */
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

typedef struct	s_parsing
{
	int i;
	char c;
	char *str;
	t_parsing *left;
	t_parsing *right;
}				t_parsing

#endif