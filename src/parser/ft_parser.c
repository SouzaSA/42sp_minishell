/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/14 11:45:34 by sde-alva         ###   ########.fr       */
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
	transition_table[NTS_PIPELINE][WORD] = 3;
	transition_table[NTS_PIPELINE][ASSIGNMENT] = 3;
	transition_table[NTS_PIPELINE][LESS] = 3;
	transition_table[NTS_PIPELINE][GREAT] = 3;
	transition_table[NTS_PIPELINE][DGREAT] = 3;
	transition_table[NTS_PIPELINE][LESSGREAT] = 3;
	transition_table[NTS_PIPELINE][DLESS] = 3;

	transition_table[NTS_PIPELINE1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_PIPELINE1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_PIPELINE1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_PIPELINE1][PIPE] = 4;
	transition_table[NTS_PIPELINE1][RBRACE] = 199; //retorna um end?

	transition_table[NTS_COMMAND][LBRACE] = 5;
	transition_table[NTS_COMMAND][WORD] = 5;
	transition_table[NTS_COMMAND][ASSIGNMENT] = 5;
	transition_table[NTS_COMMAND][LESS] = 5;
	transition_table[NTS_COMMAND][GREAT] = 5;
	transition_table[NTS_COMMAND][DGREAT] = 5;
	transition_table[NTS_COMMAND][LESSGREAT] = 5;
	transition_table[NTS_COMMAND][DLESS] = 5;

	transition_table[NTS_COMMAND1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_COMMAND1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_COMMAND1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_COMMAND1][PIPE] = 199; //retorna um end?
	transition_table[NTS_COMMAND1][RBRACE] = 199; //retorna um end?
	transition_table[NTS_COMMAND1][LESS] = 6;
	transition_table[NTS_COMMAND1][GREAT] = 6;
	transition_table[NTS_COMMAND1][DGREAT] = 6;
	transition_table[NTS_COMMAND1][LESSGREAT] = 6;
	transition_table[NTS_COMMAND1][DLESS] = 6;

	transition_table[NTS_SUBSHELL][LBRACE] = 7;

	transition_table[NTS_SIMPLE_CMD][WORD] = 8;
	transition_table[NTS_SIMPLE_CMD][ASSIGNMENT] = 8;
	transition_table[NTS_SIMPLE_CMD][LESS] = 8;
	transition_table[NTS_SIMPLE_CMD][GREAT] = 8;
	transition_table[NTS_SIMPLE_CMD][DGREAT] = 8;
	transition_table[NTS_SIMPLE_CMD][LESSGREAT] = 8;
	transition_table[NTS_SIMPLE_CMD][DLESS] = 8;

	transition_table[NTS_SIMPLE_CMD1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD1][PIPE] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD1][RBRACE] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD1][WORD] = 9; //retorna um end?

	transition_table[NTS_SIMPLE_CMD2][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD2][AND_IF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD2][OR_IF] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD2][PIPE] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD2][RBRACE] = 199; //retorna um end?
	transition_table[NTS_SIMPLE_CMD2][WORD] = 10;
	transition_table[NTS_SIMPLE_CMD2][LESS] = 10;
	transition_table[NTS_SIMPLE_CMD2][GREAT] = 10;
	transition_table[NTS_SIMPLE_CMD2][DGREAT] = 10;
	transition_table[NTS_SIMPLE_CMD2][LESSGREAT] = 10;
	transition_table[NTS_SIMPLE_CMD2][DLESS] = 10;

	transition_table[NTS_PREFIX][ASSIGNMENT] = 11;
	transition_table[NTS_PREFIX][LESS] = 11;
	transition_table[NTS_PREFIX][GREAT] = 11;
	transition_table[NTS_PREFIX][DGREAT] = 11;
	transition_table[NTS_PREFIX][LESSGREAT] = 11;
	transition_table[NTS_PREFIX][DLESS] = 11;

	transition_table[NTS_PREFIX1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][PIPE] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][RBRACE] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][WORD] = 199; //retorna um end?
	transition_table[NTS_PREFIX1][LESS] = 12;
	transition_table[NTS_PREFIX1][GREAT] = 12;
	transition_table[NTS_PREFIX1][DGREAT] = 12;
	transition_table[NTS_PREFIX1][LESSGREAT] = 12;
	transition_table[NTS_PREFIX1][DLESS] = 12;

	transition_table[NTS_SULFIX][WORD] = 13;
	transition_table[NTS_SULFIX][LESS] = 13;
	transition_table[NTS_SULFIX][GREAT] = 13;
	transition_table[NTS_SULFIX][DGREAT] = 13;
	transition_table[NTS_SULFIX][LESSGREAT] = 13;
	transition_table[NTS_SULFIX][DLESS] = 13;

	transition_table[NTS_SULFIX1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_SULFIX1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_SULFIX1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_SULFIX1][PIPE] = 199; //retorna um end?
	transition_table[NTS_SULFIX1][RBRACE] = 199; //retorna um end?
	transition_table[NTS_SULFIX1][WORD] = 14;
	transition_table[NTS_SULFIX1][LESS] = 14;
	transition_table[NTS_SULFIX1][GREAT] = 14;
	transition_table[NTS_SULFIX1][DGREAT] = 14;
	transition_table[NTS_SULFIX1][LESSGREAT] = 14;
	transition_table[NTS_SULFIX1][DLESS] = 14;

	transition_table[NTS_REDIRECT_LIST][LESS] = 15;
	transition_table[NTS_REDIRECT_LIST][GREAT] = 15;
	transition_table[NTS_REDIRECT_LIST][DGREAT] = 15;
	transition_table[NTS_REDIRECT_LIST][LESSGREAT] = 15;
	transition_table[NTS_REDIRECT_LIST][DLESS] = 15;

	transition_table[NTS_REDIRECT_LIST1][TOK_EOF] = 199; //retorna um end?
	transition_table[NTS_REDIRECT_LIST1][AND_IF] = 199; //retorna um end?
	transition_table[NTS_REDIRECT_LIST1][OR_IF] = 199; //retorna um end?
	transition_table[NTS_REDIRECT_LIST1][PIPE] = 199; //retorna um end?
	transition_table[NTS_REDIRECT_LIST1][RBRACE] = 199; //retorna um end?
	transition_table[NTS_REDIRECT_LIST1][LESS] = 16;
	transition_table[NTS_REDIRECT_LIST1][GREAT] = 16;
	transition_table[NTS_REDIRECT_LIST1][DGREAT] = 16;
	transition_table[NTS_REDIRECT_LIST1][LESSGREAT] = 16;
	transition_table[NTS_REDIRECT_LIST1][DLESS] = 16;

	transition_table[NTS_IO_REDIRECT][LESS] = 17;
	transition_table[NTS_IO_REDIRECT][GREAT] = 17;
	transition_table[NTS_IO_REDIRECT][DGREAT] = 17;
	transition_table[NTS_IO_REDIRECT][LESSGREAT] = 17;
	transition_table[NTS_IO_REDIRECT][DLESS] = 17;

	transition_table[NTS_IO_FILE][LESS] = 18;
	transition_table[NTS_IO_FILE][GREAT] = 18;
	transition_table[NTS_IO_FILE][DGREAT] = 18;
	transition_table[NTS_IO_FILE][LESSGREAT] = 18;
	transition_table[NTS_IO_FILE][DLESS] = 18;

	transition_table[NTS_IO_HERE][DLESS] = 19;
}
