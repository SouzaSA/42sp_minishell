/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_assignments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:11:54 by sde-alva          #+#    #+#             */
/*   Updated: 2022/02/26 21:16:55 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_executor.h"

static void			ft_add_var(t_shell *shell, t_dictionary *element);
static t_dictionary	*ft_set_dictionary_element(char *assignment);

int	ft_assignments(t_shell *shell, t_list *assign)
{
	int				rtn;
	t_dictionary	*element;

	rtn = 0;
	if (assign)
	{
		while (rtn == 0 && assign)
		{
			element = ft_set_dictionary_element((char *)assign->content);
			if (!element->key || !element->value)
				rtn = 1;
			ft_add_var(shell, element);
			assign = assign->next;
		}
		if (rtn)
			ft_lstclear(&shell->vars, ft_destroy_dictionary_element);
	}
	return (rtn);
}

static t_dictionary	*ft_set_dictionary_element(char *assignment)
{
	int				len_key;
	int				len_val;
	t_dictionary	*element;

	element = NULL;
	if (assignment)
	{
		element = (t_dictionary *)malloc(sizeof(t_dictionary));
		if (!element)
			return (NULL);
		len_key = ft_strchr(assignment, '=') - assignment;
		element->key = ft_substr(assignment, 0, len_key);
		len_val = ft_strchr(assignment, '\0') - ft_strchr(assignment, '=');
		element->value = ft_substr(assignment, len_key + 1, len_val);
	}
	return (element);
}

static void	ft_add_var(t_shell *shell, t_dictionary *element)
{
	char	*key;
	t_list	*node;

	key = element->key;
	node = shell->vars;
	while (node && ft_strcmp(key, ((t_dictionary *)node->content)->key))
		node = node->next;
	if (node)
	{
		free(((t_dictionary *)node->content)->value);
		((t_dictionary *)node->content)->value = element->value;
		free(element->key);
		free(element);
	}
	else
		ft_lstadd_back(&shell->vars, ft_lstnew(element));
}
