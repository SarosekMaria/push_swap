/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:13:29 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/29 15:16:39 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_pa(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp;

	if (*top_b != NULL)
	{
		tmp = *top_b;
		*top_b = (*top_b)->next;
		if (*top_b)
			(*top_b)->prev = NULL;
		tmp->next = *top_a;
		if (*top_a)
			(*top_a)->prev = tmp;
		*top_a = tmp;
		(*top_a)->prev = NULL;
	}
}
