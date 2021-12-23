#include "ft_parser.h"

t_node	*ft_new_node(enum e_node_type type)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	ft_memset(node, 0, sizeof(t_node));
	node->type = type;
	return (node);
}
