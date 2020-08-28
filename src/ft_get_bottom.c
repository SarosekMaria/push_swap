/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:38:04 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/17 21:20:39 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

t_stack		*ft_get_bottom(t_stack **top)
{
	t_stack	*tmp;

	if (top != NULL)
	{
		tmp = *top;
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}
