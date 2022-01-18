#include "ft_parser.h"

void	***ft_init_transition_table(void)
{
	int	i;
	int	j;
	void	(***transition_table)(t_list **, enum e_tok_type);

	i = 0;
	transition_table = (void ***)malloc(20 * sizeof(int **));
	while (i < 20)
	{
		*transition_table = (void **)malloc(14 * sizeof(void *));
		i++;
	}
	i = 0;
	while ( i < 20)
	{
		j = 0;
		while (j < 14)
		{
			transition_table[i][j] = NULL;
			j++;
		}
		i++;
	}
	ft_init_tt_start_and_or(transition_table);
	ft_init_tt_pipeline_subshell(transition_table);
	ft_init_tt_command_io_file_here(transition_table);
	ft_init_tt_simple_cmd(transition_table);
	ft_init_tt_prefix_redirect(transition_table);
	ft_init_tt_sulfix(transition_table);
	ft_init_tt_redirect_list(transition_table);
}

void	ft_init_tt_start_and_or(void ***transition_table)
{
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
}

void	ft_init_tt_pipeline_subshell(void ***transition_table)
{
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
	transition_table[NTS_SUBSHELL][TS_LBRACE] = &ft_subshell;
}

void	ft_init_tt_command_io_file_here(void ***transition_table)
{
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
	transition_table[NTS_IO_FILE][TS_LESS] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_GREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_DGREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_LESSGREAT] = &ft_io_file;
	transition_table[NTS_IO_FILE][TS_DLESS] = &ft_io_file;
	transition_table[NTS_IO_HERE][TS_DLESS] = &ft_io_here;
}

void	ft_init_tt_simple_cmd(void ***transition_table)
{
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
}

void	ft_init_tt_prefix_redirect(void ***transition_table)
{
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
	transition_table[NTS_IO_REDIRECT][TS_LESS] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_GREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_DGREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_LESSGREAT] = &ft_io_redirect;
	transition_table[NTS_IO_REDIRECT][TS_DLESS] = &ft_io_redirect;
}

void	ft_init_tt_sulfix(void ***transition_table)
{
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
}

void	ft_init_tt_redirect_list(void ***transition_table)
{
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
}
