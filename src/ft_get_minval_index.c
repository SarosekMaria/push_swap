/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_minval_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:59:16 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/27 20:07:30 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_get_minval_index(t_stack **top, int value, int size)
{
	t_stack	*tmp;
	int		k;

	k = 0;
	if (top != NULL)
	{
		tmp = *top;
		while (tmp && k < size)
		{
			if (tmp->value == value)
				return (k);
			tmp = tmp->next;
			k++;
		}
	}
	return (-1);
}
