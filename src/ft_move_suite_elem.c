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

void	ft_move_suite_elem(t_stack **top_a, t_stack **top_b, t_correct *cor, int fd)
{
/*	ft_printf("______________IN MOVE___________________\n");
	ft_print_stack(top_a);
	ft_print_stack(top_b);
	ft_printf("correction->sum = %d\nNOW GETCHAR\n", cor->sum);
	ft_printf("ra = %d\nrb = %d\nrr = %d\nrra = %d\nrrb = %d\nrrr = %d\nsa = %d\nsb = %d\nss = %d\n\n", cor->ra, cor->rb, cor->rr, cor->rra, cor->rrb, cor->rrr, cor->sa, cor->sb, cor->ss);
	getchar();
*/	while (cor->ra > 0)
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
	ft_pa(top_a, top_b);
	write(fd, "pa\n", 3);
}
