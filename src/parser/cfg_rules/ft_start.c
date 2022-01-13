#include "ft_parser.h"

#include "ft_parser.h"

t_ast_node	*ft_start(t_token *tok)
{
	t_ast_node	*node;
	enum e_tok_type type;

	node = NULL;
	type = tok->tok_type;
	if (type == WORD || type == LBRACE || type == ASSIGNMENT || type == LESS \
		|| type == GREAT || type == DGREAT || type == LESSGREAT \
		|| type == DLESS)
	{
		node = ft_new_node(NTS_START);
		if (node)
		{
			node->first_child = ft_and_or(tok);
			if (node->first_child)
				node->children = 1;
		}


	}
	else
	{
		ft_parser_error_msg(tok->text);
	}
	return (node);
}
