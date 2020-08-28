/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_markup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:29:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 19:25:38 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static int	ft_mi_checks(t_stack *markup_head, t_stack **top)
{
	t_stack	*tmp;
	int		index;
	int		count;

	count = 0;
	index = markup_head->i;
	tmp = markup_head;
	while (markup_head->f == 0)
	{
		if (tmp)
			tmp = tmp->next;
		if (tmp == NULL && markup_head->f == 0)
			tmp = *top;
		if (tmp->value == markup_head->value)
			markup_head->f = 1;
		if (tmp->i == index + 1 && markup_head->f == 0)
		{
			index = tmp->i;
			tmp->m = 1;
			count++;
		}
		else if (markup_head->f == 0)
			tmp->m = 0;
	}
	return (count);
}

int			ft_index_markup(t_stack **top, t_stack *markup_head)
{
	markup_head->f = 0;
	markup_head->m = 1;
	if (top != NULL && *top != NULL)
		return (ft_mi_checks(markup_head, top));
	return (0);
}
