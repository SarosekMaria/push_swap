/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_suite_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:04:14 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:26:04 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void		ft_calc_sum(t_correct **top_correct,
			t_correct **current_cor)
{
	t_correct	*tmp;
	int			min;

	min = (*current_cor)->sum;
	tmp = *top_correct;
	while (tmp)
	{
		if (tmp->sum < min)
		{
			*current_cor = tmp;
			min = tmp->sum;
		}
		tmp = tmp->next;
	}
}

t_correct		*ft_calc_variants(t_stack **top_a, t_stack **top_b,
			t_stack *elem_b, t_correct **top_correct)
{
	t_correct	*current_cor;
	int			suite_a;
	int			suite_b;

	suite_a = ft_order_num(top_a, ft_min_stack_elem(top_a));
	suite_b = ft_order_num(top_b, elem_b);
	current_cor = *top_correct;
	ft_bu_au(suite_a, suite_b, current_cor);
	current_cor = current_cor->next;
	ft_bu_ad(ft_stack_size(top_a) - suite_a, suite_b, current_cor);
	current_cor = current_cor->next;
	if (ft_stack_size(top_b) == 1)
		suite_b = 1;
	ft_bd_au(suite_a, ft_stack_size(top_b) - suite_b, current_cor);
	current_cor = current_cor->next;
	ft_bd_ad(ft_stack_size(top_a) - suite_a,
			ft_stack_size(top_b) - suite_b, current_cor);
	ft_calc_sum(top_correct, &current_cor);
	return (current_cor);
}

t_correct		*ft_calc_op(t_stack **top_a, t_stack **top_b,
			t_stack *elem_b, t_correct **top_correct)
{
	int			suite_a;
	int			suite_b;
	t_correct	*current_cor;

	suite_a = ft_find_suite_pair(top_a, elem_b);
	suite_b = ft_order_num(top_b, elem_b);
	current_cor = *top_correct;
	ft_bu_au(suite_a, suite_b, current_cor);
	current_cor = current_cor->next;
	ft_bu_ad(ft_stack_size(top_a) - suite_a, suite_b, current_cor);
	current_cor = current_cor->next;
	if (ft_stack_size(top_b) == 1)
		suite_b = 1;
	ft_bd_au(suite_a, ft_stack_size(top_b) - suite_b, current_cor);
	current_cor = current_cor->next;
	ft_bd_ad(ft_stack_size(top_a) - suite_a,
			ft_stack_size(top_b) - suite_b, current_cor);
	ft_calc_sum(top_correct, &current_cor);
	return (current_cor);
}

void			ft_find_suite_elem(t_stack **top_a, t_stack **top_b,
t_correct **top_cor, t_correct **cor_min)
{
	t_stack		*tmp;
	t_correct	*cur_min;

	cur_min = *top_cor;
	(*cor_min)->sum = ft_stack_size(top_a) + ft_stack_size(top_b);
	tmp = *top_b;
	while (tmp)
	{
		if (ft_gt(top_a, tmp) == 1)
			cur_min = ft_calc_variants(top_a, top_b, tmp, top_cor);
		else
			cur_min = ft_calc_op(top_a, top_b, tmp, top_cor);
		if (cur_min->sum < (*cor_min)->sum)
			ft_cpy_cor(cor_min, cur_min);
		ft_reinit_correct(top_cor);
		tmp = tmp->next;
	}
}
