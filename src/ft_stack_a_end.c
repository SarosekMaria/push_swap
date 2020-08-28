/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_a_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 15:14:41 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:24:03 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void	ft_stack_a_end(t_stack **top_a, int fd)
{
	int	min_elem_order;
	int	size_a;

	size_a = ft_stack_size(top_a);
	min_elem_order = ft_order_num(top_a, ft_min_stack_elem(top_a));
	if (min_elem_order <= size_a)
	{
		while (ft_is_sort_pswap_asc(top_a, size_a) == 0)
		{
			ft_ra_rb(top_a);
			write(fd, "ra\n", 3);
		}
	}
	else
	{
		while (ft_is_sort_pswap_asc(top_a, size_a) == 0)
		{
			ft_rra_rrb(top_a);
			write(fd, "rra\n", 3);
		}
	}
}
