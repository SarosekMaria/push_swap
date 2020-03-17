/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:04:11 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:32:53 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_execute(t_stack **top_a)
{
	int		fd;
	char	*line;
	t_stack	*top_b;

	line = NULL;
	top_b = NULL;
//	fd = open("instructions.txt", O_RDONLY);
//	if (fd < 0)
//		ft_printf("we fucked up with opening instructions.txt!:(\n");
	fd = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strcmp(line, "sa") == 0)
			ft_sa_sb(top_a);
		else if (ft_strcmp(line, "sb") == 0)
			ft_sa_sb(&top_b);
		else if (ft_strcmp(line, "ss") == 0)
			ft_ss(top_a, &top_b);
		else if (ft_strcmp(line, "pa") == 0)
			ft_pa(top_a, &top_b);
		else if (ft_strcmp(line, "pb") == 0)
			ft_pb(top_a, &top_b);
		else if (ft_strcmp(line, "ra") == 0)
			ft_ra_rb(top_a);
		else if (ft_strcmp(line, "rb") == 0)
			ft_ra_rb(&top_b);
		else if (ft_strcmp(line, "rr") == 0)
			ft_rr(top_a, &top_b);
		else if (ft_strcmp(line, "rra") == 0)
			ft_rra_rrb(top_a);
		else if (ft_strcmp(line, "rrb") == 0)
			ft_rra_rrb(&top_b);
		else if (ft_strcmp(line, "rrr") == 0)
			ft_rrr(top_a, &top_b);
		if (line != NULL)
			ft_strdel(&line);
//		ft_print_stack(top_a);
//		ft_print_stack(&top_b);
	}
//	if (close (fd) < 0)
//		ft_printf("we fucked up with closing instructions.txt!:(\n");
//	unlink("instructions.txt");
//	ft_print_stack(top_a);
	ft_is_sort(top_a, &top_b);
	return (1);
}
