/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/12 12:48:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

char **ft_parser(t_list *tokens)
{
	t_token	*tok;
	t_list	*parsed_cmd;

	tok = (t_token *)tokens->content;
	if (tokens && tok->tok_type == LBRACE)
}

static int	**ft_transition_table(void)
{
	int	i;
	int	**transition_table;

	transition_table = (int **)malloc(23 * sizeof(int *));
	while (i < 23)
	{
		*transition_table = (int *)malloc(12 * sizeof(int));
	}
	transition_table[2][0] = 14
	transition_table[4][0] = 14
	transition_table[7][0] = 14
	transition_table[8][0] = 14
	transition_table[12][0] = 14
	transition_table[14][0] = 14
	transition_table[16][0] = 14
	transition_table[2][1] = 14
	transition_table[4][1] = 14
	transition_table[7][1] = 14
	transition_table[8][1] = 14
	transition_table[12][1] = 14
	transition_table[14][1] = 14
	transition_table[16][1] = 14
}
