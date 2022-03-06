/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/06 16:14:30 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_get_by_limiter(int *fd, char *limiter, int lineno);
static void	ft_free_lines(char *line1, char *line2);

int	ft_here_doc(t_shell *shell, char *limiter)
{
	int	fd[2];
	int	pid;
	int	rtn;
	int	lineno;

	rtn = 0;
	if (pipe(fd) == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	ft_handle_parent_process_signals();
	pid = fork();
	if (pid == -1)
		rtn = ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (pid == 0)
	{
		ft_handle_child_process_signals();
		lineno = shell->lineno;
		ft_destroy_shell(shell);
		ft_get_by_limiter(fd, limiter, lineno);
	}
	wait(NULL);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	return (rtn);
}

static void	ft_get_by_limiter(int *fd, char *limiter, int lineno)
{
	char	*line;
	char	*line_no_nl;

	close(fd[0]);
	write(1, "> ", 2);
	line = get_next_line(0);
	while (line)
	{
		line_no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
		if (ft_strcmp(limiter, line_no_nl) == 0)
		{
			ft_free_lines(line, line_no_nl);
			close(fd[1]);
			exit(0);
		}
		if (write(fd[1], line, ft_strlen(line)) == -1)
			ft_put_msg_error("Can't write a line on pipe", FLAG_ERROR_OWN);
		ft_free_lines(line, line_no_nl);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	free(line);
	close(fd[1]);
	ft_heredoc_error(limiter, lineno);
	exit(1);
}

static void	ft_free_lines(char *line1, char *line2)
{
	free(line1);
	free(line2);
}
