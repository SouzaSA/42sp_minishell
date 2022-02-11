/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:45:35 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/10 21:23:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_executor(t_ast *ast)
{
	int rtn;

	rtn = 0;

	return (rtn);
}

static int	ft_redir(t_list *redir, int *fd_in, int *fd_out)
{
	int		rtn;
	int		open_flag;
	char	*key;
	char	*filename;
	t_list	*node;

	rtn = 0;
	node = redir;
	while (node)
	{
		key = (char *)node->content;
		filename = (char *)node->next->content;
		if (ft_strcmp(">", key) || ft_strcmp(">>", key))
		{
			if (fd_out > 0)
				close(fd_out);
			if (ft_strcmp(">", key))
				open_flag = O_CREAT | O_WRONLY | O_TRUNC;
			if (ft_strcmp(">>", key))
				open_flag = O_CREAT | O_WRONLY | O_APPEND;
			//TODO a test for open file
			fd_out = open(filename, open_flag, 0644);
		}
		else if (ft_strcmp("<", (char *)node->content))
		{
			//TODO test for open file
			fd_in = open(filename, O_RDONLY);
		}
		else if (ft_strcmp("<<", (char *)node->content))
		{
			ft_here_doc(filename);
			fd_in = 0;
		}
		else if (ft_strcmp("<>", (char *)node->content))
		{
			if (fd_in > 0)
				close(fd_in);
			fd_in = open(filename, O_RDONLY);
			//TODO test for open file
			if (fd_out > 0)
				close(fd_out);
			fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
			//TODO test for open file
		}

		node = node->next->next;
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
