/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:53:05 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 15:36:28 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_del_stack(t_stack **top)
{
	t_stack	*tmp;

	if (top != NULL)
	{
		while (*top)
		{
			tmp = (*top)->next;
			ft_del_elem_st(top);
			*top = tmp;
		}
		top = NULL;
	}
}
