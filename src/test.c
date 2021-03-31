/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboumed <alboumed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:10:08 by alboumed          #+#    #+#             */
/*   Updated: 2021/03/31 17:53:49 by alboumed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	t_value			*value;
	t_node			*left;
	t_node			*right;
};

////////////////////////////////////////////

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
