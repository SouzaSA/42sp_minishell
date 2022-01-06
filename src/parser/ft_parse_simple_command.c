/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:28:08 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/05 18:01:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_add_tree_node(t_node *cmd, t_token *tok);

t_node	*ft_parse_simple_command(t_scanner *scan, t_token *tok)
{
	t_node		*cmd;
	t_source	*src;

	if (!tok)
		return (NULL);
	cmd = new_node(NODE_COMMAND);
	src = tok->src;
	if (!cmd)
	{
		ft_free_token(tok);
		return (NULL);
	}
	tok = tokenize(scan, src);
	while (!tok->end_flag)
	{
		if (tok->text[0] == '\n')
		{
			ft_free_token(tok);
			break ;
		}
		ft_add_tree_node(cmd, tok);
	}
	return (cmd);
}

static void	ft_add_tree_node(t_node *cmd, t_token *tok)
{
	t_node		*word;

	word = new_node(NODE_VAR);
	if (!word)
	{
		free_node_tree(cmd);
		free_token(tok);
		return (NULL);
	}
	set_node_val_str(word, tok->text);
	add_child_node(cmd, word);
	free_token(tok);
}
