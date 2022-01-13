/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/13 19:30:43 by sde-alva         ###   ########.fr       */
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
    //rules
	transition_table = (int **)malloc(20 * sizeof(int *));
	while (i < 23)
	{
		*transition_table = (int *)malloc(12 * sizeof(int));
	}
	transition_table[NTS_START][LBRACE] = 0;
	transition_table[NTS_START][WORD] = 0;
	transition_table[NTS_START][ASSIGNMENT] = 0;
	transition_table[NTS_START][LESS] = 0;
	transition_table[NTS_START][GREAT] = 0;
	transition_table[NTS_START][DGREAT] = 0;
	transition_table[NTS_START][LESSGREAT] = 0;
	transition_table[NTS_START][DLESS] = 0;

	transition_table[NTS_AND_OR][LBRACE] = 1;
	transition_table[NTS_AND_OR][WORD] = 1;
	transition_table[NTS_AND_OR][ASSIGNMENT] = 1;
	transition_table[NTS_AND_OR][LESS] = 1;
	transition_table[NTS_AND_OR][GREAT] = 1;
	transition_table[NTS_AND_OR][DGREAT] = 1;
	transition_table[NTS_AND_OR][LESSGREAT] = 1;
	transition_table[NTS_AND_OR][DLESS] = 1;

	transition_table[NTS_AND_OR1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_AND_OR1][AND_IF] = 2;
	transition_table[NTS_AND_OR1][OR_IF] = 2;
	transition_table[NTS_AND_OR1][RBRACE] = 199;  //retorna um end?

	transition_table[NTS_PIPELINE][TOK_EOF] = 199;  //retorna um end?
	transition_table[NTS_PIPELINE][AND_IF] = 3;
	transition_table[NTS_PIPELINE][OR_IF] = 3;
	transition_table[NTS_PIPELINE][LBRACE] = 3;
	transition_table[NTS_PIPELINE][LBRACE] = 3;

}
