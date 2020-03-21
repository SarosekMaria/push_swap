/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creating_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:26:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:13:10 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_pswap.h"

void		ft_visualize(t_stack **top_a, t_stack **top_b, char *line)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = *top_a;
	tmp_b = *top_b;
	ft_printf("Operation: %s\n", line);
	ft_printf("***************STACK_A*************|***************STACK_B*****************\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("|%17d                 |", tmp_a->value);
			tmp_a = tmp_a->next;
		}
		if (tmp_b)
		{
			ft_printf("%18d                    |", tmp_b->value);
			tmp_b = tmp_b->next;
		}
		else
			ft_printf("                                      |");
		ft_printf("\n");
	}
	ft_printf("***********************************|***************************************\n");
	ft_printf("\n");
}
