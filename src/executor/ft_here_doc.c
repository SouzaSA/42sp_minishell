/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:26:09 by sde-alva          #+#    #+#             */
/*   Updated: 2022/03/08 15:56:02 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void	ft_hdoc_child(t_shell *shell, char *lmt, int *fd, t_cmd_data *data);
static void	ft_get_by_limiter(int *fd, char *lmt, int lineno, t_cmd_data *data);
static void	ft_clean(char **line1, char **line2, t_cmd_data *data, int *fd);

int	ft_here_doc(t_shell *shell, char *limiter, t_cmd_data *data)
{
	int	fd[2];
	int	pid;
	int	wstatus;

	if (pipe(fd) == -1)
		ft_put_msg_error(NULL, FLAG_ERROR_P);
	ft_handle_parent_process_signals();
	pid = fork();
	if (pid == -1)
		ft_put_msg_error(NULL, FLAG_ERROR_P);
	if (pid == 0)
		ft_hdoc_child(shell, limiter, fd, data);
	wait(&wstatus);
	if (!WIFSIGNALED(wstatus))
		g_exit_status = WEXITSTATUS(wstatus);
	close(fd[1]);
	if (g_exit_status == 0)
		dup2(fd[0], 0);
	else
		data->fd_in = -1;
	close(fd[0]);
	return (g_exit_status);
}

static void	ft_hdoc_child(t_shell *shell, char *lmt, int *fd, t_cmd_data *data)
{
	int	lineno;

	lineno = shell->lineno;
	ft_handle_child_process_signals();
	ft_destroy_shell(shell);
	ft_get_by_limiter(fd, lmt, lineno, data);
}

static void	ft_get_by_limiter(int *fd, char *lmt, int lno, t_cmd_data *data)
{
	char	*line;
	char	*line_no_nl;

	close(fd[0]);
	write(1, "> ", 2);
	line = get_next_line(0);
	line_no_nl = NULL;
	while (line)
	{
		line_no_nl = ft_substr(line, 0, ft_strlen(line) - 1);
		if (ft_strcmp(lmt, line_no_nl) == 0)
		{
			ft_clean(&line, &line_no_nl, data, fd);
			exit(0);
		}
		if (write(fd[1], line, ft_strlen(line)) == -1)
			ft_put_msg_error("Can't write a line on pipe", FLAG_ERROR_OWN);
		ft_clean(&line, &line_no_nl, data, NULL);
		write(1, "> ", 2);
		line = get_next_line(0);
	}
	ft_clean(&line, &line_no_nl, data, fd);
	ft_heredoc_error(lmt, lno);
	exit(1);
}

static void	ft_clean(char **line1, char **line2, t_cmd_data *data, int *fd)
{
	if (data->cmd)
		free(data->cmd);
	ft_destroy_command(&data->blk);
	ft_destroy_ast_stk(data->cmd_stk);
	free(*line1);
	*line1 = NULL;
	free(*line2);
	*line2 = NULL;
	if (fd)
		close(fd[1]);
}
