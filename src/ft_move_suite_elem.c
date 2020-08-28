/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_suite_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:05:52 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:26:19 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void	ft_instr(t_correct *cor, t_stack **top_a,
		t_stack **top_b, int fd)
{
	while (cor->rra > 0)
	{
		ft_rra_rrb(top_a);
		write(fd, "rra\n", 4);
		cor->rra--;
	}
	while (cor->rrb > 0)
	{
		ft_rra_rrb(top_b);
		write(fd, "rrb\n", 4);
		cor->rrb--;
	}
	while (cor->rrr > 0)
	{
		ft_rrr(top_a, top_b);
		write(fd, "rrr\n", 4);
		cor->rrr--;
	}
}

void		ft_move_suite_elem(t_stack **top_a, t_stack **top_b,
		t_correct *cor, int fd)
{
	while (cor->ra > 0)
	{
		ft_ra_rb(top_a);
		write(fd, "ra\n", 3);
		cor->ra--;
	}
	while (cor->rb > 0)
	{
		ft_ra_rb(top_b);
		write(fd, "rb\n", 3);
		cor->rb--;
	}
	while (cor->rr > 0)
	{
		ft_rr(top_a, top_b);
		write(fd, "rr\n", 3);
		cor->rr--;
	}
	ft_instr(cor, top_a, top_b, fd);
	ft_pa(top_a, top_b);
	write(fd, "pa\n", 3);
}
