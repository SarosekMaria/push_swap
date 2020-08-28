/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:42:56 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 20:13:35 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_gt(t_stack **top_a, t_stack *elem)
{
	t_stack	*tmp;

	tmp = *top_a;
	if (top_a != NULL && *top_a != NULL)
	{
		while (tmp)
		{
			if (tmp->i > elem->i)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}
