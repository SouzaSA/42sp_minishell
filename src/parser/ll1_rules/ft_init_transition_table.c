/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_transition_table.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:15:15 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/20 20:17:32 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_fill_transition_table(void (***tt)(t_list **, enum e_symbol))
{
	int	i;
	int	j;

	i = 0;
	while (i < NUM_NTS)
	{
		j = 0;
		while (j < NUM_TS)
		{
			tt[i][j] = NULL;
			j++;
		}
		i++;
	}
	ft_init_tt_start_and_or(tt);
	ft_init_tt_pipeline_subshell(tt);
	ft_init_tt_command_io_file_here(tt);
	ft_init_tt_simple_cmd(tt);
	ft_init_tt_prefix_redirect(tt);
	ft_init_tt_sulfix(tt);
	ft_init_tt_redir_list(tt);
}

void	ft_init_tt_start_and_or(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_START][TS_LBRACE - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_WORD - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_ASSIGNMENT - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_LESS - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_GREAT - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_DGREAT - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_LESSGREAT - NUM_NTS] = &ft_start;
	tt[NTS_START][TS_DLESS - NUM_NTS] = &ft_start;
	tt[NTS_AND_OR][TS_LBRACE - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_WORD - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_ASSIGNMENT - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_LESS - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_GREAT - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_DGREAT - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_LESSGREAT - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR][TS_DLESS - NUM_NTS] = &ft_and_or;
	tt[NTS_AND_OR1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_AND_OR1][TS_AND_IF - NUM_NTS] = &ft_and_or1;
	tt[NTS_AND_OR1][TS_OR_IF - NUM_NTS] = &ft_and_or1;
	tt[NTS_AND_OR1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
}

void	ft_init_tt_pipeline_subshell(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_PIPELINE][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_PIPELINE][TS_AND_IF - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_OR_IF - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_LBRACE - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_WORD - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_ASSIGNMENT - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_LESS - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_GREAT - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_DGREAT - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_LESSGREAT - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE][TS_DLESS - NUM_NTS] = &ft_pipeline;
	tt[NTS_PIPELINE1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_PIPELINE1][TS_AND_IF - NUM_NTS] = &ft_epsilon;
	tt[NTS_PIPELINE1][TS_OR_IF - NUM_NTS] = &ft_epsilon;
	tt[NTS_PIPELINE1][TS_PIPE - NUM_NTS] = &ft_pipeline1;
	tt[NTS_PIPELINE1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SUBSHELL][TS_LBRACE - NUM_NTS] = &ft_subshell;
}
