/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/09 21:22:15 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_executor(t_ast *ast)
{
	int rtn;

	rtn = 0;

	return (rtn);
}

static int	ft_redir(t_list *redir)
{
	int		rtn;
	t_list	*node;

	rtn = 0;
	node = redir;
	while (node)
	{
		if (ft_strcmp(">", (char *)node->content))
			//TODO
		if (ft_strcmp(">>", (char *)node->content))
			//TODO
		if (ft_strcmp("<", (char *)node->content))
			//TODO
		if (ft_strcmp("<<", (char *)node->content))
			//TODO
		if (ft_strcmp("<>", (char *)node->content))
			//TODO
		node = node->next;
	}
	return (rtn);
}

static char	**ft_cmd_lst_to_array(t_list *cmd)
{
	int		i;
	t_list	*node;
	t_list	*node_old;
	char 	**cmd_array;

	i = 0;
	cmd_array = (char **)malloc(ft_lstsize(cmd) * sizeof(char *));
	node = cmd;
	while (node)
	{
		node_old = node;
		cmd_array[i] = (char *)node->content;
		node = node->next;
		i++;
		free(node);
	}
	return (cmd_array);
}

static int	ft_do_assign(t_list *assign)
{
	int	rtn;

	rtn = 0;

}