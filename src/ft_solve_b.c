/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 13:41:42 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 15:52:55 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void		ft_inc(t_correct **cor, t_correct **top_correct)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		*cor = ft_init_correct();
		(*cor)->next = *top_correct;
		*top_correct = *cor;
		i++;
	}
}

void			ft_solve_b(t_stack **top_a, t_stack **top_b, int fd)
{
	t_correct	*top_correct;
	t_correct	*cor;
	int			size_of_stack;

	size_of_stack = ft_stack_size(top_b);
	top_correct = ft_init_correct();
	ft_inc(&cor, &top_correct);
	cor = ft_init_correct();
	while (size_of_stack > 0)
	{
		ft_find_suite_elem(top_a, top_b, &top_correct, &cor);
		ft_move_suite_elem(top_a, top_b, cor, fd);
		size_of_stack--;
	}
	ft_stack_a_end(top_a, fd);
	free(cor);
	while (top_correct)
	{
		cor = top_correct;
		top_correct = top_correct->next;
		free(cor);
	}
}
