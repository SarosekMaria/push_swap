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

void	ft_bd_ad(int suite_a, int suite_b, t_correct *current_cor)
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
//	ft_printf("FT_BD_AD: rra = %d, rrb = %d, rrr = %d, sum = %d\n",current_cor->rra, current_cor->rrb, current_cor->rrr, current_cor->sum);
}

void	ft_bd_au(int suite_a, int suite_b, t_correct *current_cor)
{
	current_cor->ra = suite_a;
	current_cor->sum = suite_a + suite_b;
	current_cor->rrb = suite_b;
//	ft_printf("FT_BD_AU: ra = %d, rrb = %d, sum = %d\n",current_cor->ra, current_cor->rrb, current_cor->sum);
}

void	ft_bu_ad(int suite_a, int suite_b, t_correct *current_cor)
{
	current_cor->rra = suite_a;
	current_cor->rb = suite_b;
	current_cor->sum = suite_a + suite_b;
//	ft_printf("FT_BU_AD: rra = %d, rb = %d, sum = %d\n",current_cor->rra, current_cor->rb, current_cor->sum);
}

void	ft_bu_au(int suite_a, int suite_b, t_correct *current_cor)
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
//	ft_printf("FT_BU_AU: ra = %d, rb = %d, rr = %d, sum = %d\n",current_cor->ra, current_cor->rb, current_cor->rr, current_cor->sum);
}


int			ft_find_suite_pair(t_stack **top_a, t_stack *elem_b)
{
	t_stack	*tmp;
	int		ind_differ;
	int		min_differ;
	int		order_num;

	order_num = 0;
	min_differ = 0;
//ft_printf("ft_find_suite_pair: elem_b->i = %d\n", elem_b->i);
	tmp = *top_a;
	while (tmp)
	{
		if (tmp->i > elem_b->i)
		{
			ind_differ = tmp->i - elem_b->i;
			if (min_differ == 0)
			{
				min_differ = tmp->i - elem_b->i;
				order_num = ft_order_num(top_a, tmp);
//ft_printf("ft_find_suite_pair: suite_pair->value = %d, order_num = %d\n", tmp->value, ft_order_num(top_a, tmp));
			}
			else if (ind_differ < min_differ)
			{
				min_differ = ind_differ;
				order_num = ft_order_num(top_a, tmp);
//ft_printf("ft_find_suite_pair: suite_pair->value = %d, order_num = %d\n", tmp->value, ft_order_num(top_a, tmp));
			}
		}
		tmp = tmp->next;
	}
	return (order_num);
}
