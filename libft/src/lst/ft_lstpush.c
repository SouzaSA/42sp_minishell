#include "libft.h"

void	ft_lstpush(t_list **lst, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	ft_lstadd_front(lst, new);
}
