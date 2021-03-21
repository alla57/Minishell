/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:27:27 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/21 17:37:30 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (ft_isalpha(s1[i]) && ft_isalpha(s2[i]))
	{
		if (!(s1[i] == s2[i] || s1[i] == s2[i] + 32 || s1[i] == s2[i] - 32))
			break ;
		++i;
	}
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
