/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort_pswap_dsc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:53:31 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/26 10:44:24 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int		ft_is_sort_pswap_dsc(t_stack **top, size_t size)
{
	t_stack	*tmp;

	if (top != NULL && size)
	{
		tmp = *top;
		while (tmp->next && size > 1)
		{
			if (tmp->value < (tmp->next)->value)
				return (0);
			tmp = tmp->next;
			size--;
		}
	}
	return (1);
}
