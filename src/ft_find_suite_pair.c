/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_suite_pair.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:34:17 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:25:06 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_bd_ad(int suite_a, int suite_b, t_correct *current_cor)
{
	if (suite_a > suite_b)
	{
		current_cor->rra = suite_a - suite_b;
		current_cor->rrr = suite_b;
		current_cor->sum = current_cor->rra + current_cor->rrr;
	}
	else
	{
		current_cor->rrb = suite_b - suite_a;
		current_cor->rrr = suite_a;
		current_cor->sum = current_cor->rrb + current_cor->rrr;
	}
}

void		ft_bd_au(int suite_a, int suite_b, t_correct *current_cor)
{
	current_cor->ra = suite_a;
	current_cor->sum = suite_a + suite_b;
	current_cor->rrb = suite_b;
}

void		ft_bu_ad(int suite_a, int suite_b, t_correct *current_cor)
{
	current_cor->rra = suite_a;
	current_cor->rb = suite_b;
	current_cor->sum = suite_a + suite_b;
}

void		ft_bu_au(int suite_a, int suite_b, t_correct *current_cor)
{
	if (suite_a >= suite_b)
	{
		current_cor->ra = suite_a - suite_b;
		current_cor->rr = suite_b;
		current_cor->sum = current_cor->ra + current_cor->rr;
	}
	else
	{
		current_cor->rb = suite_b - suite_a;
		current_cor->rr = suite_a;
		current_cor->sum = current_cor->rb + current_cor->rr;
	}
}

int			ft_find_suite_pair(t_stack **top_a, t_stack *elem_b)
{
	t_stack	*tmp;
	int		min_dif;
	int		order_num;

	order_num = 0;
	min_dif = 0;
	tmp = *top_a;
	while (tmp)
	{
		if (tmp->i > elem_b->i)
		{
			if (min_dif == 0 || tmp->i - elem_b->i < min_dif)
			{
				min_dif = tmp->i - elem_b->i;
				order_num = ft_order_num(top_a, tmp);
			}
		}
		tmp = tmp->next;
	}
	return (order_num);
}
