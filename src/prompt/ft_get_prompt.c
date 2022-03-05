/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 08:22:07 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 14:30:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_colors.h"

static char	*ft_create_prompt(char *cwd);

char	*ft_get_prompt(void)
{
	char	*cwd;

	cwd = ft_calloc(1024, sizeof(char));
	getcwd(cwd, 1024);
	return (ft_create_prompt(cwd));
}

static char	*ft_create_prompt(char *cwd)
{
	char	*tmp;
	char	*prompt;

	prompt = ft_strjoin(CYAN, cwd);
	free(cwd);
	tmp = ft_strjoin(prompt, END_COLOR);
	free(prompt);
	prompt = ft_strjoin(tmp, PROMPT_DOLLAR);
	free(tmp);
	return (prompt);
}
