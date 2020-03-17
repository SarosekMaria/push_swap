/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:09:33 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 21:24:21 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

void		ft_sa_sb(t_stack **top)
{
	t_stack *tmp;

	if (*top != NULL && ft_stack_size(top) > 1)
	{
		tmp = (*top)->next;
		(*top)->next = tmp->next;
		tmp->next = *top;
		tmp->prev = NULL;//
		if ((*top)->next)
			(*top)->next->prev = *top;//
		(*top)->prev = tmp;//
		*top = tmp;
	}
}
