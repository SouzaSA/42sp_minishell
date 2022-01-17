/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_symbol_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:29:32 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/16 12:33:39 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

enum e_symbol	*ft_new_symbol(enum e_symbol symbol)
{
	enum e_symbol	*sym;

	sym = (enum e_symbol *)malloc(sizeof(enum e_symbol));
	*sym = symbol;
	return (sym);
}
