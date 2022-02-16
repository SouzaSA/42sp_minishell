/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grammar_symbols.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:56:57 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/15 15:19:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAMMAR_SYMBOLS_H
# define FT_GRAMMAR_SYMBOLS_H

# define NUM_TS 14
# define NUM_NTS 20

enum e_symbol
{
	NTS_START,
	NTS_AND_OR,
	NTS_AND_OR1,
	NTS_PIPELINE,
	NTS_PIPELINE1,
	NTS_COMMAND,
	NTS_COMMAND1,
	NTS_SUBSHELL,
	NTS_SIMPLE_CMD,
	NTS_SIMPLE_CMD1,
	NTS_SIMPLE_CMD2,
	NTS_PREFIX,
	NTS_PREFIX1,
	NTS_SULFIX,
	NTS_SULFIX1,
	NTS_REDIR_LST,
	NTS_REDIR_LST1,
	NTS_IO_REDIRECT,
	NTS_IO_FILE,
	NTS_IO_HERE,
	TS_PIPE,
	TS_LBRACE,
	TS_RBRACE,
	TS_AND_IF,
	TS_OR_IF,
	TS_LESS,
	TS_GREAT,
	TS_DGREAT,
	TS_LESSGREAT,
	TS_DLESS,
	TS_ASSIGNMENT,
	TS_WORD,
	TS_EOF,
	TS_UNKNOWN,
};
#endif