/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tt1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:16:24 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/19 17:05:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_init_tt_command_io_file_here(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_COMMAND][TS_LBRACE - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_WORD - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_ASSIGNMENT - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_LESS - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_GREAT - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_DGREAT - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_LESSGREAT - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND][TS_DLESS - NUM_NTS] = &ft_command;
	tt[NTS_COMMAND1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_COMMAND1][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_COMMAND1][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_COMMAND1][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_COMMAND1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_COMMAND1][TS_LESS - NUM_NTS] = ft_command1;
	tt[NTS_COMMAND1][TS_GREAT - NUM_NTS] = ft_command1;
	tt[NTS_COMMAND1][TS_DGREAT - NUM_NTS] = ft_command1;
	tt[NTS_COMMAND1][TS_LESSGREAT - NUM_NTS] = ft_command1;
	tt[NTS_COMMAND1][TS_DLESS - NUM_NTS] = ft_command1;
	tt[NTS_IO_FILE][TS_LESS - NUM_NTS] = &ft_io_file;
	tt[NTS_IO_FILE][TS_GREAT - NUM_NTS] = &ft_io_file;
	tt[NTS_IO_FILE][TS_DGREAT - NUM_NTS] = &ft_io_file;
	tt[NTS_IO_FILE][TS_LESSGREAT - NUM_NTS] = &ft_io_file;
	tt[NTS_IO_FILE][TS_DLESS - NUM_NTS] = &ft_io_file;
	tt[NTS_IO_HERE][TS_DLESS - NUM_NTS] = &ft_io_here;
}

void	ft_init_tt_simple_cmd(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_SIMPLE_CMD][TS_WORD - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_ASSIGNMENT - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_LESS - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_GREAT - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_DGREAT - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_LESSGREAT - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD][TS_DLESS - NUM_NTS] = &ft_simple_cmd;
	tt[NTS_SIMPLE_CMD1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD1][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD1][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD1][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD1][TS_WORD - NUM_NTS] = &ft_simple_cmd1;
	tt[NTS_SIMPLE_CMD2][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD2][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD2][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD2][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD2][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SIMPLE_CMD2][TS_WORD - NUM_NTS] = &ft_simple_cmd2;
	tt[NTS_SIMPLE_CMD2][TS_LESS - NUM_NTS] = &ft_simple_cmd2;
	tt[NTS_SIMPLE_CMD2][TS_GREAT - NUM_NTS] = &ft_simple_cmd2;
	tt[NTS_SIMPLE_CMD2][TS_DGREAT - NUM_NTS] = &ft_simple_cmd2;
	tt[NTS_SIMPLE_CMD2][TS_LESSGREAT - NUM_NTS] = &ft_simple_cmd2;
	tt[NTS_SIMPLE_CMD2][TS_DLESS - NUM_NTS] = &ft_simple_cmd2;
}

void	ft_init_tt_prefix_redirect(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_PREFIX][TS_ASSIGNMENT - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX][TS_LESS - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX][TS_GREAT - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX][TS_DGREAT - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX][TS_LESSGREAT - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX][TS_DLESS - NUM_NTS] = &ft_cmd_prefix;
	tt[NTS_PREFIX1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_WORD - NUM_NTS] = &ft_epsilon;
	tt[NTS_PREFIX1][TS_LESS - NUM_NTS] = &ft_cmd_prefix1;
	tt[NTS_PREFIX1][TS_GREAT - NUM_NTS] = &ft_cmd_prefix1;
	tt[NTS_PREFIX1][TS_DGREAT - NUM_NTS] = &ft_cmd_prefix1;
	tt[NTS_PREFIX1][TS_LESSGREAT - NUM_NTS] = &ft_cmd_prefix1;
	tt[NTS_PREFIX1][TS_DLESS - NUM_NTS] = &ft_cmd_prefix1;
	tt[NTS_IO_REDIRECT][TS_LESS - NUM_NTS] = &ft_io_redirect;
	tt[NTS_IO_REDIRECT][TS_GREAT - NUM_NTS] = &ft_io_redirect;
	tt[NTS_IO_REDIRECT][TS_DGREAT - NUM_NTS] = &ft_io_redirect;
	tt[NTS_IO_REDIRECT][TS_LESSGREAT - NUM_NTS] = &ft_io_redirect;
	tt[NTS_IO_REDIRECT][TS_DLESS - NUM_NTS] = &ft_io_redirect;
}

void	ft_init_tt_sulfix(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_SULFIX][TS_WORD - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX][TS_LESS - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX][TS_GREAT - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX][TS_DGREAT - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX][TS_LESSGREAT - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX][TS_DLESS - NUM_NTS] = &ft_cmd_sulfix;
	tt[NTS_SULFIX1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_SULFIX1][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_SULFIX1][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_SULFIX1][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SULFIX1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_SULFIX1][TS_WORD - NUM_NTS] = &ft_cmd_sulfix1;
	tt[NTS_SULFIX1][TS_LESS - NUM_NTS] = &ft_cmd_sulfix1;
	tt[NTS_SULFIX1][TS_GREAT - NUM_NTS] = &ft_cmd_sulfix1;
	tt[NTS_SULFIX1][TS_DGREAT - NUM_NTS] = &ft_cmd_sulfix1;
	tt[NTS_SULFIX1][TS_LESSGREAT - NUM_NTS] = &ft_cmd_sulfix1;
	tt[NTS_SULFIX1][TS_DLESS - NUM_NTS] = &ft_cmd_sulfix1;
}

void	ft_init_tt_redir_list(void (***tt)(t_list **, enum e_symbol))
{
	tt[NTS_REDIR_LST][TS_LESS - NUM_NTS] = &ft_cmd_redir_list;
	tt[NTS_REDIR_LST][TS_GREAT - NUM_NTS] = &ft_cmd_redir_list;
	tt[NTS_REDIR_LST][TS_DGREAT - NUM_NTS] = &ft_cmd_redir_list;
	tt[NTS_REDIR_LST][TS_LESSGREAT - NUM_NTS] = &ft_cmd_redir_list;
	tt[NTS_REDIR_LST][TS_DLESS - NUM_NTS] = &ft_cmd_redir_list;
	tt[NTS_REDIR_LST1][TS_EOF - NUM_NTS] = &ft_epsilon;
	tt[NTS_REDIR_LST1][TS_AND - NUM_NTS] = &ft_epsilon;
	tt[NTS_REDIR_LST1][TS_OR - NUM_NTS] = &ft_epsilon;
	tt[NTS_REDIR_LST1][TS_PIPE - NUM_NTS] = &ft_epsilon;
	tt[NTS_REDIR_LST1][TS_RBRACE - NUM_NTS] = &ft_epsilon;
	tt[NTS_REDIR_LST1][TS_LESS - NUM_NTS] = &ft_cmd_redir_list1;
	tt[NTS_REDIR_LST1][TS_GREAT - NUM_NTS] = &ft_cmd_redir_list1;
	tt[NTS_REDIR_LST1][TS_DGREAT - NUM_NTS] = &ft_cmd_redir_list1;
	tt[NTS_REDIR_LST1][TS_LESSGREAT - NUM_NTS] = &ft_cmd_redir_list1;
	tt[NTS_REDIR_LST1][TS_DLESS - NUM_NTS] = &ft_cmd_redir_list1;
}
