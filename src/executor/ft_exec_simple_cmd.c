/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:07:45 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/05 21:14:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_exec_simple_cmd(t_node *node)
{
	t_node	*child;
	int		argc;
	char	**argv;/* keep 1 for the terminating NULL arg */
	char	*str;

	if(!node)
		return (0);
	child = node->first_child;
	if (!child)
		return (0);
	argc = 0;
	argv = (char **)malloc(1025);/* keep 1 for the terminating NULL arg */

	while(child)
	{
		str = child->val.str;
		argv[argc] = malloc(strlen(str)+1);

		if(!argv[argc])
		{
			free_argv(argc, argv);
			return 0;
		}

		strcpy(argv[argc], str);
		if(++argc >= max_args)
		{
			break;
		}
		child = child->next_sibling;
	}
	argv[argc] = NULL;
	pid_t child_pid = 0;
	if((child_pid = fork()) == 0)
	{
		do_exec_cmd(argc, argv);
		fprintf(stderr, "error: failed to execute command: %s\n",
			strerror(errno));
		if(errno == ENOEXEC)
			exit(126);
		else if(errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if(child_pid < 0)
	{
		fprintf(stderr, "error: failed to fork command: %s\n",
			strerror(errno));
		return 0;
	}
	int status = 0;
	waitpid(child_pid, &status, 0);
	free_argv(argc, argv);
	return 1;
}
