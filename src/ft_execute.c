/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:04:11 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 15:29:57 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static void	ft_commands(char *line, t_stack **top_a, t_stack **top_b)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa_sb(top_a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sa_sb(top_b);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(top_a, top_b);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(top_a, top_b);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(top_a, top_b);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra_rb(top_a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_ra_rb(top_b);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(top_a, top_b);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra_rrb(top_a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rra_rrb(top_b);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(top_a, top_b);
}

int			ft_execute(t_stack **top_a, int v)
{
	char	*line;
	t_stack	*top_b;

	line = NULL;
	top_b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_val_instr(line))
			return (-1);
		ft_commands(line, top_a, &top_b);
		if (v == 1)
			ft_visualize(top_a, &top_b, line);
		if (line != NULL)
			ft_strdel(&line);
	}
	ft_is_sort(top_a, &top_b);
	return (1);
}
