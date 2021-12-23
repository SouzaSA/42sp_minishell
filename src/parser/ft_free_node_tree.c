#include "ft_parser.h"

void	ft_free_node_tree(t_node *node)
{
	t_node	*child;
	t_node	*next;

	if (!node)
		return ;
	child = node->first_child;
	while (child)
	{
		next = child->next_sibling;
		ft_free_node_tree(child);
		child = next;
	}
	if (node->val_type == VAL_STR)
	{
		if (node->val.str)
			free(node->val.str);
	}
	free(node);
}
