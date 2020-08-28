/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:50:13 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 18:23:14 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_indexing(t_stack **top)
{
	t_stack	*tmp;
	int		*m;
	size_t	i;

	if (top != NULL && *top != NULL)
	{
		m = ft_init_mas(top, ft_stack_size(top));
		tmp = *top;
		while (tmp)
		{
			i = 0;
			while (m[i] != tmp->value)
				i++;
			tmp->i = i;
			tmp = tmp->next;
		}
		free(m);
		m = NULL;
	}
}
