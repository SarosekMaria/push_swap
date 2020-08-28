/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:06:29 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/17 19:56:01 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_print_stack(t_stack **top)
{
	t_stack *tmp;

	if (top != NULL)
	{
		tmp = *top;
		while (tmp)
		{
			ft_printf("%d\n", tmp->value);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}
