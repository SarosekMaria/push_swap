/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gt_markup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:30:44 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 21:25:31 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int		ft_gt_markup(t_stack **top, t_stack *markup_head)
{
	t_stack *tmp;
	int     count;
	int     index;
	int		f;

	f = 0;
	index = markup_head->i;
	count = 0;
	markup_head->m = 1;
	tmp = markup_head;
	if (top != NULL && *top != NULL)
	{
		while (f == 0)
		{
			if (tmp)
				tmp = tmp->next;
			if (tmp == NULL && f == 0)
				tmp = *top;
			if (tmp->value == markup_head->value)
				f = 1;
			if (tmp->i > index && f == 0)
			{
				index = tmp->i;
				tmp->m = 1;
				count++;
			}
			else if (f == 0)
				tmp->m = 0;
		}
	}
	return (count);
}
