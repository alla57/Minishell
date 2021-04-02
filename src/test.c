/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:10:08 by alboumed          #+#    #+#             */
/*   Updated: 2021/04/02 16:54:48 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef enum	e_op
{
	OP_ADD, OP_MUL
}				t_op;

typedef union	u_value
{
	t_op	op;
	int		num;
	char	*str;
}				t_value;

typedef enum	e_token_type
{
	IS_OP, IS_NUM
}				t_token_type;

typedef struct s_node t_node;

struct s_node
{
	t_token_type	token_type; //facultative
	t_value			value;
	t_node			*left;
	t_node			*right;
};

typedef enum	e_priotity
{
	HIGH_PRIORITY, LOW_PRIORITY
}				t_priority;

t_op	get_op(char *str)
{
	t_op	op;
	if (str[0] == '+')
		op = OP_ADD;
	else if (str[0] == '*')
		op = OP_MUL;
	return (op);
}

int		token_isdigit(char *str)
{
	if (ft_isdigit(str[0]))
		return (1);
	return (0);
}

int		token_isop(char *str)
{
	if (str[0] == '+' || str[0] == '*')
		return (1);
	return (0);
}

t_node	*add_node(t_token_type token_type, t_value value)
{
	t_node new_node;

	if (!(new_node = malloc(sizeof(t_node))))
		return (NULL);
	new_node.token_type = token_type;
	new_node.value = value;
	node.left = NULL;
	node.right = NULL;
	return (&new_node);
}

t_node	*add_num_node(t_node *node, char *token)
{
	node = add_node(IS_NUM, ft_atoi(token));
	return (node);
}

t_node	*add_op_node(t_node *node, char *token)
{
	node = add_node(IS_OP, get_op(token));
	return (node);
}

t_node	*test(char *token)
{
	t_node *node;

	if (token_isdigit(token))
		add_num_node(node, token);
	else if (token_isop(token))
		add_op_node(node, token);
	return (node);
}

t_node	*parser(char **token)
{
	t_node	*current_node;
	t_node	*prev_node;
	int i;

	i = 0;
	// if (token_isdigit(token[i]))
		add_num_node(current_node, token[i]);
	// else if (token_isop(token[i]))
	prev_node = current_node;
		add_op_node(current_node, token[++i]);
	current_node->left = prev_node;

//////////////////////////////////////////////////////
	prev_node = NULL;
	current_node = test(current_node, token[i]);
	if (current_node->token_type == IS_OP)
	{
		if (current_node->value == OP_MUL)
		{
			current_node->left = prev_node;
			self();
		}
		else if (current_node->value == OP_ADD)
		{
			
		}
		current_node->left = prev_node;
		current_node->right = 
	}
	else if (current_node->token_type == IS_NUM)
	{
		if (!token[i + 1])
			prev_node->right = current_node;
		else
			prev_node = current_node;
	}
//////////////////////////////////////////////////////

	if (get_op(token[i + 2]) == OP_MUL)
	{
		add_op_node(current_node, token[++i]);
	}
	// else
		// return (NULL);
	get_next_token();
}

char **tokenizer(char *str)
{
	if (!str)
		return (NULL);
	return (ft_split(str, ' '));
}

int calcul(char *str)
{
	char **stack;

	stack = tokenizer(str);
	parser();
}

////////////////////////////////////////////
/*
typedef enum	e_op
{
	OP_ADD, OP_MUL
}				t_op;

typedef struct	s_op_node
{
	t_op	op;
	t_node	*left;
	t_node	*right;
}				t_op_node;

typedef struct	s_num_leaf
{
	int		num;
}				t_num_leaf;

typedef union	u_node_type
{
	t_op_node	op;
	t_num_leaf	num;
}				t_node_type;

typedef struct s_node t_node;

struct	s_node
{
	t_node_type		*node_type;
	t_node			*base;
};
*/