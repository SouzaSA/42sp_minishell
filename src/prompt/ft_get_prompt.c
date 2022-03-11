/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 08:22:07 by edpaulin          #+#    #+#             */
/*   Updated: 2022/03/05 15:21:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "ft_colors.h"

static char	*ft_create_prompt(char *cwd);

char	*ft_get_prompt(void)
{
	char	*cwd;

	cwd = ft_calloc(PROMPT_SIZE, sizeof(char));
	if (!cwd)
	{
		ft_put_msg_error("Cannot allocate memory for cwd", FLAG_ERROR_OWN);
		return (NULL);
	}
	if (!getcwd(cwd, PROMPT_SIZE))
	{
		ft_put_msg_error("Path too large", FLAG_ERROR_OWN);
		return (NULL);
	}
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
