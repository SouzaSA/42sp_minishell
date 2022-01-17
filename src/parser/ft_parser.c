/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:18:16 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/16 21:45:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int ft_parser(t_list *tokens)
{
	t_token	*tok;
	t_list	*parsed_cmd;
	void	(***tt)(t_list **, enum e_tok_type);
	t_list *symbol_stack;
	int		symbol;

	tt = ft_transition_table();
	ft_lstpush(&symbol_stack, ft_new_symbol(TS_EOF));
	ft_lstpush(&symbol_stack, ft_new_symbol(NTS_START));

	while (ft_lstsize(symbol_stack) > 0)
	{
		if (((t_token *)tokens)->tok_type == *((enum e_symbol *)symbol_stack->content))
		{
			tokens->next;
			free(ft_lstpop(symbol_stack));
		}
		else
		{
			symbol = ft_lstpop(symbol_stack);
			tt[symbol][((t_token *)tokens)->tok_type](tt, ((t_token *)tokens)->tok_type);
			free(symbol);
		}
	}
	//TODO - Define error criteria and return values.
}

static void	***ft_transition_table(void)
{
	int	i;
	void	(***transition_table)(t_list **, enum e_tok_type);
    //rules
	transition_table = (void ***)malloc(20 * sizeof(int **));
	while (i < 23)
	{
		*transition_table = (void **)malloc(14 * sizeof(void *));
	}
	transition_table[NTS_START][TS_LBRACE] = &ft_start;
	transition_table[NTS_START][TS_WORD] = &ft_start;
	transition_table[NTS_START][TS_ASSIGNMENT] = &ft_start;
	transition_table[NTS_START][TS_LESS] = &ft_start;
	transition_table[NTS_START][TS_GREAT] = &ft_start;
	transition_table[NTS_START][TS_DGREAT] = &ft_start;
	transition_table[NTS_START][TS_LESSGREAT] = &ft_start;
	transition_table[NTS_START][TS_DLESS] = &ft_start;

	transition_table[NTS_AND_OR][TS_LBRACE] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_WORD] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_ASSIGNMENT] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_LESS] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_GREAT] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_DGREAT] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_LESSGREAT] = &ft_and_or;
	transition_table[NTS_AND_OR][TS_DLESS] = &ft_and_or;
	transition_table[NTS_AND_OR1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_AND_OR1][TS_AND_IF] = &ft_and_or1;
	transition_table[NTS_AND_OR1][TS_OR_IF] = &ft_and_or1;
	transition_table[NTS_AND_OR1][TS_RBRACE] = &ft_epsilon;

	transition_table[NTS_PIPELINE][TS_EOF] = &ft_epsilon;
	transition_table[NTS_PIPELINE][TS_AND_IF] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_OR_IF] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_LBRACE] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_WORD] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_ASSIGNMENT] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_LESS] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_GREAT] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_DGREAT] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_LESSGREAT] = &ft_pipeline;
	transition_table[NTS_PIPELINE][TS_DLESS] = &ft_pipeline;
	transition_table[NTS_PIPELINE1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_PIPELINE1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_PIPELINE1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_PIPELINE1][TS_PIPE] = &ft_pipeline1;
	transition_table[NTS_PIPELINE1][TS_RBRACE] = &ft_epsilon;

	transition_table[NTS_COMMAND][TS_LBRACE] = &ft_command;
	transition_table[NTS_COMMAND][TS_WORD] = &ft_command;
	transition_table[NTS_COMMAND][TS_ASSIGNMENT] = &ft_command;
	transition_table[NTS_COMMAND][TS_LESS] = &ft_command;
	transition_table[NTS_COMMAND][TS_GREAT] = &ft_command;
	transition_table[NTS_COMMAND][TS_DGREAT] = &ft_command;
	transition_table[NTS_COMMAND][TS_LESSGREAT] = &ft_command;
	transition_table[NTS_COMMAND][TS_DLESS] = &ft_command;
	transition_table[NTS_COMMAND1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_COMMAND1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_COMMAND1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_COMMAND1][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_COMMAND1][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_COMMAND1][TS_LESS] = ft_command1;
	transition_table[NTS_COMMAND1][TS_GREAT] = ft_command1;
	transition_table[NTS_COMMAND1][TS_DGREAT] = ft_command1;
	transition_table[NTS_COMMAND1][TS_LESSGREAT] = ft_command1;
	transition_table[NTS_COMMAND1][TS_DLESS] = ft_command1;

	transition_table[NTS_SUBSHELL][TS_LBRACE] = &ft_subshell;

	transition_table[NTS_SIMPLE_CMD][TS_WORD] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_ASSIGNMENT] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_LESS] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_GREAT] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_DGREAT] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_LESSGREAT] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD][TS_DLESS] = &ft_simple_cmd;
	transition_table[NTS_SIMPLE_CMD1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD1][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD1][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD1][TS_WORD] = &ft_simple_cmd1;

	transition_table[NTS_SIMPLE_CMD2][TS_EOF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD2][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD2][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD2][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD2][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_SIMPLE_CMD2][TS_WORD] = &ft_simple_cmd2;
	transition_table[NTS_SIMPLE_CMD2][TS_LESS] = &ft_simple_cmd2;
	transition_table[NTS_SIMPLE_CMD2][TS_GREAT] = &ft_simple_cmd2;
	transition_table[NTS_SIMPLE_CMD2][TS_DGREAT] = &ft_simple_cmd2;
	transition_table[NTS_SIMPLE_CMD2][TS_LESSGREAT] = &ft_simple_cmd2;
	transition_table[NTS_SIMPLE_CMD2][TS_DLESS] = &ft_simple_cmd2;

	transition_table[NTS_PREFIX][TS_ASSIGNMENT] = &ft_cmd_prefix;
	transition_table[NTS_PREFIX][TS_LESS] = &ft_cmd_prefix;
	transition_table[NTS_PREFIX][TS_GREAT] = &ft_cmd_prefix;
	transition_table[NTS_PREFIX][TS_DGREAT] = &ft_cmd_prefix;
	transition_table[NTS_PREFIX][TS_LESSGREAT] = &ft_cmd_prefix;
	transition_table[NTS_PREFIX][TS_DLESS] = &ft_cmd_prefix;

	transition_table[NTS_PREFIX1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_WORD] = &ft_epsilon;
	transition_table[NTS_PREFIX1][TS_LESS] = &ft_cmd_prefix1;
	transition_table[NTS_PREFIX1][TS_GREAT] = &ft_cmd_prefix1;
	transition_table[NTS_PREFIX1][TS_DGREAT] = &ft_cmd_prefix1;
	transition_table[NTS_PREFIX1][TS_LESSGREAT] = &ft_cmd_prefix1;
	transition_table[NTS_PREFIX1][TS_DLESS] = &ft_cmd_prefix1;

	transition_table[NTS_SULFIX][TS_WORD] = &ft_cmd_sulfix;
	transition_table[NTS_SULFIX][TS_LESS] = &ft_cmd_sulfix;
	transition_table[NTS_SULFIX][TS_GREAT] = &ft_cmd_sulfix;
	transition_table[NTS_SULFIX][TS_DGREAT] = &ft_cmd_sulfix;
	transition_table[NTS_SULFIX][TS_LESSGREAT] = &ft_cmd_sulfix;
	transition_table[NTS_SULFIX][TS_DLESS] = &ft_cmd_sulfix;

	transition_table[NTS_SULFIX1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_SULFIX1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_SULFIX1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_SULFIX1][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_SULFIX1][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_SULFIX1][TS_WORD] = &ft_cmd_sulfix1;
	transition_table[NTS_SULFIX1][TS_LESS] = &ft_cmd_sulfix1;
	transition_table[NTS_SULFIX1][TS_GREAT] = &ft_cmd_sulfix1;
	transition_table[NTS_SULFIX1][TS_DGREAT] = &ft_cmd_sulfix1;
	transition_table[NTS_SULFIX1][TS_LESSGREAT] = &ft_cmd_sulfix1;
	transition_table[NTS_SULFIX1][TS_DLESS] = &ft_cmd_sulfix1;

	transition_table[NTS_REDIRECT_LIST][TS_LESS] = &ft_cmd_redirect_list;
	transition_table[NTS_REDIRECT_LIST][TS_GREAT] = &ft_cmd_redirect_list;
	transition_table[NTS_REDIRECT_LIST][TS_DGREAT] = &ft_cmd_redirect_list;
	transition_table[NTS_REDIRECT_LIST][TS_LESSGREAT] = &ft_cmd_redirect_list;
	transition_table[NTS_REDIRECT_LIST][TS_DLESS] = &ft_cmd_redirect_list;
	transition_table[NTS_REDIRECT_LIST1][TS_EOF] = &ft_epsilon;
	transition_table[NTS_REDIRECT_LIST1][TS_AND_IF] = &ft_epsilon;
	transition_table[NTS_REDIRECT_LIST1][TS_OR_IF] = &ft_epsilon;
	transition_table[NTS_REDIRECT_LIST1][TS_PIPE] = &ft_epsilon;
	transition_table[NTS_REDIRECT_LIST1][TS_RBRACE] = &ft_epsilon;
	transition_table[NTS_REDIRECT_LIST1][TS_LESS] = &ft_cmd_redirect_list1;
	transition_table[NTS_REDIRECT_LIST1][TS_GREAT] = &ft_cmd_redirect_list1;
	transition_table[NTS_REDIRECT_LIST1][TS_DGREAT] = &ft_cmd_redirect_list1;
	transition_table[NTS_REDIRECT_LIST1][TS_LESSGREAT] = &ft_cmd_redirect_list1;
	transition_table[NTS_REDIRECT_LIST1][TS_DLESS] = &ft_cmd_redirect_list1;

	transition_table[NTS_IO_REDIRECT][TS_LESS] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_GREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_DGREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_LESSGREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_DLESS] = &ft_io_redirect;

	transition_table[NTS_IO_FILE][TS_LESS] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_GREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_DGREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_LESSGREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_DLESS] = &ft_io_file;

	transition_table[NTS_IO_HERE][TS_DLESS] = &ft_io_here;
	return  (transition_table);
}
