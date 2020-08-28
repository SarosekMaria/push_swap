/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_three_elem_sort_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:44:55 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 13:38:35 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void	ft_first(t_stack **top_a, t_stack **top_b, int mid, int fd)
{
	ft_sa_sb(top_a);
	write(fd, "sa\n", 3);
	ft_pb(top_a, top_b);
	write(fd, "pb\n", 3);
	ft_sa_sb(top_a);
	write(fd, "sa\n", 3);
	ft_pa(top_a, top_b);
	write(fd, "pa\n", 3);
	if ((*top_a)->value == mid)
	{
		ft_sa_sb(top_a);
		write(fd, "sa\n", 3);
	}
}

static void	ft_second(t_stack **top_a, t_stack **top_b, int mid, int fd)
{
	if ((*top_a)->next->value < mid)
	{
		ft_sa_sb(top_a);
		write(fd, "sa\n", 3);
	}
	else
	{
		ft_pb(top_a, top_b);
		write(fd, "pb\n", 3);
		ft_sa_sb(top_a);
		write(fd, "sa\n", 3);
		ft_pa(top_a, top_b);
		write(fd, "pa\n", 3);
		ft_sa_sb(top_a);
		write(fd, "sa\n", 3);
	}
}

void		ft_three_elem_sort_a(t_stack **top_a, t_stack **top_b,
int fd, int mid)
{
	if (ft_is_sort_pswap_asc(top_a, 3) == 0)
	{
		if ((*top_a)->value > mid)
			ft_first(top_a, top_b, mid, fd);
		else if ((*top_a)->value == mid)
			ft_second(top_a, top_b, mid, fd);
		else
		{
			ft_pb(top_a, top_b);
			write(fd, "pb\n", 3);
			ft_sa_sb(top_a);
			write(fd, "sa\n", 3);
			ft_pa(top_a, top_b);
			write(fd, "pa\n", 3);
		}
	}
}
