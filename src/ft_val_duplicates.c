/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_duplicates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:21:55 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/15 18:55:53 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_val_duplicates(t_stack **top)
{
	t_stack *tmp;
	t_stack	*current;

	if (top != NULL)
	{
		current = *top;
		while (current->next)
		{
			tmp = current->next;
			while (tmp)
			{
				if (current->value == tmp->value)
					return (0);
				tmp = tmp->next;
			}
			current = current->next;
		}
	}
	return (1);
}
