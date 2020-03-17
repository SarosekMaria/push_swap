/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:52:28 by sassassi          #+#    #+#             */
/*   Updated: 2020/02/26 09:45:21 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			checker(int argc, char **argv)
{
	int		i;
	t_stack	*top_a;
	int		f;

	f = 0;
	top_a = NULL;
	i = argc - 1;
	if (argc > 1)
	{
		while (i > 0)
		{
			if (!ft_val_dig(argv[i]))
			{
				write(2, "Error\n", 6);
				f = 1;
				break ;
			}
			top_a = ft_add_elem(&top_a, ft_atoi(argv[i]));
			i--;
		}
		if (f == 0)
		{
			if (!ft_val_duplicates(&top_a))
			{
				write(2, "Error\n", 6);
				ft_del_stack(&top_a);
				return (0);
			}
			if (!ft_val_instr())
			{
				write(2, "Error\n", 6);
				ft_del_stack(&top_a);
				return (0);
			}
			ft_execute(&top_a);
		}
	}
	return (2);
}
