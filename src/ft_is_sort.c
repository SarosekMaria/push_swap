/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:33:21 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 16:23:51 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void	ft_clear(t_stack **top_a, t_stack **top_b)
{
	write(1, "KO\n", 3);
	ft_del_stack(top_a);
	ft_del_stack(top_b);
}

void		ft_is_sort(t_stack **top_a, t_stack **top_b)
{
	t_stack	*tmp_a;

	if (top_a != NULL)
	{
		if (ft_stack_size(top_b) > 0)
		{
			ft_clear(top_a, top_b);
			return ;
		}
		tmp_a = *top_a;
		while (tmp_a->next)
		{
			if (tmp_a->value >= (tmp_a->next)->value)
			{
				ft_clear(top_a, top_b);
				return ;
			}
			tmp_a = tmp_a->next;
		}
	}
	write(1, "OK\n", 3);
	ft_del_stack(top_a);
	ft_del_stack(top_b);
}
