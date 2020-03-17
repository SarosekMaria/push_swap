/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_stack_elem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:39:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 14:43:07 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

t_stack		*ft_min_stack_elem(t_stack **top)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *top;
	min = tmp;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
