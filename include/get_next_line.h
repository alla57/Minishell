/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:55:41 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/18 11:13:40 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
int		ft_strchr_mod(const char *s, int c);
char	*ft_strjoin_mod(char *s1, char const *s2);
char	*ft_strbefore(char *s, char c);
char	*ft_strafter(char *s, char c);
int		get_next_line(int fd, char **line);

#endif
