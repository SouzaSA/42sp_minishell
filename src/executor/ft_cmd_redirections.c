/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:14:23 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/17 17:47:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static int	ft_redir_out(char *filename, int *fd_out);
static int	ft_append(char *filename, int *fd_out);
static int	ft_redir_in(char *filename, int *fd_in);
static int	ft_redir_in_out(char *filename, int *fd_in, int *fd_out);

int	ft_redirections(t_list *redir, int *fd_in, int *fd_out)
{
	int		rtn;
	char	*key;
	char	*filename;
	t_list	*node;

	rtn = 0;
	node = redir;
	while (rtn == 0 && node)
	{
		key = (char *)node->content;
		filename = (char *)node->next->content;
		if (ft_strcmp(">", key) == 0)
			rtn = ft_redir_out(filename, fd_out);
		else if (ft_strcmp(">>", key) == 0)
			rtn = ft_append(filename, fd_out);
		else if (ft_strcmp("<", key) == 0)
			rtn = ft_redir_in(filename, fd_in);
		else if (ft_strcmp("<<", key) == 0)
			ft_here_doc(filename); //TODO clean things when error on gnl
		else if (ft_strcmp("<>", key) == 0)
			ft_redir_in_out(filename, fd_in, fd_out);
		node = node->next->next;
	}
	return (rtn);
}

static int	ft_redir_out(char *filename, int *fd_out)
{
	int	rtn;
	int	open_flag;

	rtn = 0;
	if (*fd_out > 1)
		close(*fd_out);
	if (filename)
	{
		open_flag = O_CREAT | O_WRONLY | O_TRUNC;
		*fd_out = open(filename, open_flag, 0664);
		if (*fd_out < 0)
			rtn = 1;
	}
	if (rtn)
		ft_put_msg_error(filename, FLAG_ERROR_P);
	return (rtn);
}

static int	ft_append(char *filename, int *fd_out)
{
	int	rtn;
	int	open_flag;

	rtn = 0;
	if (*fd_out > 1)
		close(*fd_out);
	if (filename)
	{
		open_flag = O_CREAT | O_WRONLY | O_APPEND;
		*fd_out = open(filename, open_flag, 0664);
		if (*fd_out < 0)
			rtn = 1;
	}
	if (rtn)
		ft_put_msg_error(filename, FLAG_ERROR_P);
	return (rtn);
}

static int	ft_redir_in(char *filename, int *fd_in)
{
	int	rtn;

	rtn = 0;
	if (*fd_in > 0)
		close(*fd_in);
	if (filename)
	{
		*fd_in = open(filename, O_RDONLY);
		if (*fd_in < 0)
			rtn = 1;
	}
	if (rtn)
		ft_put_msg_error(filename, FLAG_ERROR_P);
	return (rtn);
}

static int	ft_redir_in_out(char *filename, int *fd_in, int *fd_out)
{
	int	rtn;
	int	open_flag;

	rtn = 0;
	if (*fd_in < 0)
	{
		open_flag = O_CREAT | O_WRONLY | O_APPEND;
		*fd_out = open(filename, open_flag, 0664);
		close(*fd_out);
		*fd_out = 0;
	}
	if (filename)
	{
		*fd_in = open(filename, O_RDONLY);
		if (*fd_in < 0)
			rtn = 1;
	}
	return (rtn);
}
