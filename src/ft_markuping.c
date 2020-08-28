/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markuping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:35:55 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:25:52 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_markuping(t_stack **top, int (*mark_f)(t_stack **, t_stack *),
		t_help *help)
{
	t_stack	*tmp;
	int		max_count;
	int		count;

	count = 0;
	max_count = 0;
	tmp = *top;
	help->markup_head = *top;
	while (tmp)
	{
		count = mark_f(top, tmp);
		if (count >= max_count && tmp->i < help->markup_head->i)
		{
			max_count = count;
			help->markup_head = tmp;
		}
		tmp = tmp->next;
	}
	mark_f(top, help->markup_head);
	help->count = max_count;
}
