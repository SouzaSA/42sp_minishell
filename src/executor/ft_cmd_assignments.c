/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_assignments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/19 17:36:43 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

int	ft_assignments(t_shell *shell, t_list *assign)
{
	int				rtn;
	int				len;
	t_dictionary	*element;

	rtn = 0;
	if (assign)
	{
		element = (t_dictionary *)malloc(sizeof(t_dictionary));
		if (!element)
			rtn = 1;
		while (rtn == 0 && assign)
		{
			len = ft_strchr((const char *)assign->content, '=') - \
				(char *)assign->content;
			element->key = ft_substr((const char *)assign->content, 0, len);
			len = ft_strchr((const char *)assign->content, '\0') - \
				ft_strchr((const char *)assign->content, '=');
			element->value = ft_substr((const char *)assign->content, 0, len);
			if (!element->key || !element->value)
				rtn = 1;
			ft_lstadd_back(&shell->vars, ft_lstnew(element));
			assign = assign->next;
		}
		if (rtn)
			ft_lstclear(&shell->vars, ft_destroy_dictionary_element);
	}
	return (rtn);
}
