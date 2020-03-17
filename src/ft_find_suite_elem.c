/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_suite_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:04:14 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 21:47:20 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

t_correct			*ft_calc_op(t_stack **top_a, t_stack **top_b, t_stack *elem_b, t_correct **top_correct)
{
	int			min;
	int			suite_a;
	int			suite_b;
	t_correct	*tmp;
	t_correct	*current_cor;
	
	suite_a = ft_find_suite_pair(top_a, elem_b);
	suite_b = ft_order_num(top_b, elem_b);
ft_printf("suite_a = %d, suite_b = %d\n", suite_a, suite_b);
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
	min = current_cor->sum;
	tmp = *top_correct;
	ft_printf("for element %d in b sums are:\n", elem_b->value);
	while (tmp)
	{
		ft_printf("sum = %d\n", tmp->sum);
		if (tmp->sum < min)
			current_cor = tmp;
		tmp = tmp->next;
	}
	return (current_cor);
}

void			ft_find_suite_elem(t_stack **top_a, t_stack **top_b, t_correct **top_correct, t_correct **cor_min)
{
	t_stack		*tmp;
	t_correct	*current_min;

	current_min = *top_correct;
	(*cor_min)->sum = ft_stack_size(top_b) + 2;
	tmp = *top_b;
	while (tmp)
	{
ft_printf("In ft_find_suite_elem: tmp->value = %d\n", tmp->value);
		if (ft_gt(top_a, tmp) == 1)
		{
ft_printf("ft_gt!!!ft_order_num(top_b, tmp) = %d\n", ft_order_num(top_b, tmp));
			if (ft_order_num(top_b, tmp) <= (int)ft_stack_size(top_b) / 2)
			{
				current_min->rb = ft_order_num(top_b, tmp);
				current_min->sum = current_min->rb;
			}
			else
			{
				current_min->rrb = ft_stack_size(top_b) - ft_order_num(top_b, tmp);
				current_min->sum = current_min->rrb;
			}
		}
		else
			current_min = ft_calc_op(top_a, top_b, tmp, top_correct);
		if (current_min->sum < (*cor_min)->sum)
			ft_cpy_cor(cor_min, current_min);
ft_printf("current sum = %d, cor_min->sum = %d,NOW WOULD BE GETCHAR\n", current_min->sum, (*cor_min)->sum);
getchar();
		ft_reinit_correct(top_correct);
		tmp = tmp->next;
	}
}
