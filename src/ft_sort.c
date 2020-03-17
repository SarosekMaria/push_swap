/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:38:30 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:25:20 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_need_pushb(t_stack **top_a)
{
	t_stack	*tmp;

	tmp = *top_a;
	while (tmp)
	{
		if (tmp->m == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_need_sa(t_stack **top_a, t_help *help,
		int (*mark_f)(t_stack**, t_stack*))
{
	int		count;
	t_stack	*tmp;

	tmp = *top_a;
	count = 0;
//ft_printf("before: top = %d, top->next = %d, top->m = %d\n", (*top_a)->value, (*top_a)->next->value, (*top_a)->m);
	ft_sa_sb(top_a);
	count = mark_f(top_a, help->markup_head);
//ft_printf("count = %d, max_count = %d\n", count, help->count);
	ft_sa_sb(top_a);
	mark_f(top_a, help->markup_head);
//ft_printf("after: top = %d, top->next = %d, top->m = %d\n", (*top_a)->value, (*top_a)->next->value, (*top_a)->m);
	if (count > help->count)
	{
		help->count = count;
		return (1);
	}
	return (0);
}

void		ft_sort(t_stack **top_a, t_stack **top_b,
		int (*mark_f)(t_stack**, t_stack*), t_help *help)
{
	t_stack	*tmp;
	tmp = *top_a;
	while (tmp)
	{
//		ft_printf("%d ---- %d\n", tmp->value, tmp->m);
		tmp = tmp->next;
	}

	while (ft_need_pushb(top_a) == 1)
	{
//ft_printf("%d", (*top_a)->value);
		if (ft_need_sa(top_a, help, mark_f) == 1)
		{
//ft_printf("--------------need sa--------------\n");
			ft_sa_sb(top_a);
			mark_f(top_a, help->markup_head);
			write(help->fd, "sa\n", 3);
		}
		else if ((*top_a)->m == 0)
		{
//ft_printf("---%d-----------need pb--------------\n", (*top_a)->m);
			ft_pb(top_a, top_b);
			write(help->fd, "pb\n", 3);
		}
		else
		{
//ft_printf("---%d-----------need ra--------------\n", (*top_a)->m);
			ft_ra_rb(top_a);
			write(help->fd, "ra\n", 3);
		}
//		getchar();
	}
	ft_solve_b(top_a, top_b, help->fd);//вот здесь можно передавать полностью help, чтобы использовать как-то его свободные поля
}
