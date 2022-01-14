#include "libft.h"

void	*ft_lstpop(t_list **lst, void (*del)(void *))
{
	void	*content;

	content = NULL;
	if (*lst)
	{
		content = (*lst)->content;
		ft_lstdel_front(lst, del);
	}
	return (content);
}
