/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:41:40 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 19:36:59 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

t_stack		*ft_cpy_stack(t_stack **dst, t_stack **src)
{
	t_stack *tmp;

	if (src != NULL && *src != NULL)
	{
		tmp = ft_get_bottom(src);
		while (tmp)
		{
			*dst = ft_add_elem(dst, tmp->value);
			(*dst)->i = tmp->i;
			tmp = tmp->prev;
		}
	}
	return (*dst);
}
