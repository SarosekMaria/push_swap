/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:35:18 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 19:38:43 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

size_t		ft_stack_size(t_stack **top)
{
	size_t	len;
	t_stack	*tmp;

	tmp = *top;
	len = 0;
	if (*top != NULL)
	{
		while (tmp)
		{
			tmp = tmp->next;
			len++;
		}
	}
	return (len);
}
