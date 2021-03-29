/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:57:01 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/29 18:05:59 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	IS_EXPR,
	IS_INVALID
}				t_token_type;

typedef struct	s_parsing t_parsing;

struct	s_parsing
{
	t_op			op;
	char			*str;
	t_token_type	token_type;
	int				value;
	t_parsing		*base;
	t_parsing		*left;
	t_parsing		*right;
};

char *skip_spaces(char *str)
{
	int i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	return (str + i);
}

int is_operation(t_parsing *parsing)
{
	parsing->left->str = skip_spaces(parsing->left->str);
	if (parsing->left->str[0] == '+')
		parsing->op = OP_ADD;
	else if (parsing->left->str[0] == '*')
		parsing->op = OP_MUL;
	else
		return (0);
	parsing->token_type = IS_OP;
	parsing->right->str = skip_spaces(parsing->left->str + 1);
	return (1);
}

int left_value(t_parsing *parsing)
{
	int i;

	i = 0;
	if (ft_isdigit(parsing->str[i]))
	{
		parsing->left->base = parsing;
		parsing->left->token_type = IS_VAL;
		parsing->left->value = ft_atoi(parsing->str);
		while (ft_isdigit(parsing->str[i]))
			++i;
		parsing->left->str = parsing->str + i;
		return (1);
	}
	return (0);
}

int right_value(t_parsing *parsing)
{
	int i;

	i = 0;
	if (ft_isdigit(parsing->str[i]))
	{
		parsing->right->base = parsing;
		parsing->right->token_type = IS_VAL;
		parsing->right->value = ft_atoi(parsing->str);
		while (ft_isdigit(parsing->str[i]))
			++i;
		parsing->right->str = parsing->str + i;
		return (1);
	}
	return (0);
}

void tokenizer(t_parsing *parsing)
{
	int i;
	char **tokens;

	i = 0;
	// if (left_value(parsing))
	// 	;
	// else if (is_operation(parsing))
	// 	;
	// right_value(parsing);
	tokens = ft_split(parsing->str);
}

int ft_parsing(char *src)
{
	t_parsing parsing;
	parsing.str = src;
	tokenizer(&parsing);
}