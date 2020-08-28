/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:44:17 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 19:58:55 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

t_stack		*ft_add_elem(t_stack **top, int value)
{
	t_stack *new_elem;

	new_elem = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->m = 0;
	new_elem->i = 0;
	if (top != NULL && *top != NULL)
	{
		new_elem->next = *top;
		(*top)->prev = new_elem;
	}
	else
		new_elem->next = NULL;
	new_elem->prev = NULL;
	top = &new_elem;
	return (*top);
}
