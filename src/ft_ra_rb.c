/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:33:19 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/05 21:50:42 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pswap.h"

void		ft_ra_rb(t_stack **top)
{
	t_stack	*tmp;

	if (*top != NULL)
	{
		tmp = (*top)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *top;
		(*top)->prev = tmp;//
		tmp = *top;
		*top = (*top)->next;
		tmp->next = NULL;
		(*top)->prev = NULL;//
	}
}
