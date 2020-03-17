/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:39:34 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/05 21:57:44 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"
//it is a fucking shit - rewrite! or check... maybe right
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
		(*top)->prev = NULL;//
		tmp->next = NULL;
		head->prev = *top;//
	}
}
