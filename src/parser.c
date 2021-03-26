/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:57:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/26 16:51:16 by alboumed         ###   ########.fr       */
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

typedef enum	e_token_type
{
	IS_VAL,
	IS_OP,
	IS_SPACE,
	IS_INVALID
}				t_token_type;

typedef struct	s_jesaispas
{
	t_token_type current_token;
	t_token_type next_token;
}				t_jesaispas;

typedef struct	s_token
{
	char	*str;
	t_op	op;
	t_token left;
	t_token right;
}				t_token;

t_token_type value_type(char *src)
{
	int i;
}

void is_operation(t_token token)
{
	if (token->str[0] == '+')
		token->op = OP_ADD;
	else if (token->str[0] == '*')
		token->op = OP_MUL;
	else
		return ;
	token->str += 1;
}

int is_integer(char *src)
{
	int i;
	int nb;

	i = 0;
	if (ft_isdigit(src[i]))
	{
		nb = ft_atoi(src);
		while (ft_isdigit(src[i]))
			++i;
	}
	return (nb);
}

int check_current_token(char *src)
{
	int i;

	if (is_integer(src))
}

int parsing(char *src)
{
	int		i;
	t_op	op;

	i = 0;
	check_current_token(src);
}

int node_add(char *str)
{
	int res;

	if (current_token is number && next_token is number)
		res = current_token + next_token;
	else
		which_node(next_node);
}

int which_node(char *str)
{
	if (wh)
}

int main (void)
{
	t_parsing		calc;
	t_token_type	token_type;
	char			*src;
	int				res;

	src = "3 + 4";
	res = parsing(src);
	printf("%d\n", res);
	return (0);
}