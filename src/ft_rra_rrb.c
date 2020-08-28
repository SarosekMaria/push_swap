/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:39:34 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 19:38:10 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_rra_rrb(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*head;

	if (*top != NULL && ft_stack_size(top) > 1)
	{
		head = *top;
		while ((*top)->next)
		{
			if ((((*top)->next))->next == NULL)
				tmp = *top;
			*top = (*top)->next;
		}
		(*top)->next = head;
		(*top)->prev = NULL;
		tmp->next = NULL;
		head->prev = *top;
	}
}
