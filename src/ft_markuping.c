/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markuping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:35:55 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 21:10:07 by sassassi         ###   ########.fr       */
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
//ft_printf("tmp->value = %d, count = %d, tmp->i = %d, max_count = %d\n", tmp->value, count, tmp->i, max_count);
		tmp = tmp->next;
	}
	mark_f(top, help->markup_head);
	help->count = max_count;
//	ft_printf("markup_head->value = %d, help->count = %d\n", help->markup_head->value,  help->count);
	tmp = *top;
	while (tmp)
	{
		ft_printf("%d ---- %d\n", tmp->value, tmp->m);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
}
