/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:55:07 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 19:52:18 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_order_num(t_stack **top, t_stack *elem)
{
	int		order_num;
	t_stack	*tmp;
	order_num = 0;
	if (top && *top)
	{
		if (ft_stack_size(top) > 1)
		{
			tmp = *top;
			while (tmp != elem)
			{
				tmp = tmp->next;
				order_num++;
			}
		}
	}
	return (order_num);
}
