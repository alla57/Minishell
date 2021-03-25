/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:57:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/25 16:28:00 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef union	u_val
{
	int nb;
	char *expr;
}				t_val;

typedef enum	e_op
{
	OP_ADD,
	OP_MUL
}				t_op;

typedef enum	e_valtype
{
	IS_VAL,
	IS_OP,
	IS_SPACE
}				t_valtype;

typedef struct	s_parsing
{
	char *token;
	t_parsing left;
	t_parsing right;
}				t_parsing;

int sum(t_parsing *calc)
{
	int i;
}

t_valtype value_type(src)
{
	int i;
}

int parsing(char *src)
{
	int i;

	if (s)
}

int main (void)
{
	t_parsing calc;
	t_op OP;
	t_valtype valtype;
	char *src;
	int res;

	src = "3 + 4";
	res = parsing(src);
	printf("%d\n", res);
	return (0);
}