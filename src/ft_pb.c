/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:04:51 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 19:36:48 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_pb(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	if (*top_a != NULL)
	{
		tmp = *top_a;
		*top_a = (*top_a)->next;
		if (*top_a)
			(*top_a)->prev = NULL;
		tmp->next = *top_b;
		if (*top_b)
			(*top_b)->prev = tmp;
		*top_b = tmp;
		(*top_b)->prev = NULL;
	}
}
