/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:52:28 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:34:09 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void	ft_last_val_c(t_stack *top_a, int v)
{
	if (!ft_val_duplicates(&top_a))
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}
/*	if (!ft_val_instr())
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}*/
	if (ft_execute(&top_a, v) == -1)
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}
//	ft_del_stack(&top_a);
}

void		ft_split_val_c(char *s, t_stack *top_a, int v)
{
	char    **argv;
	int     i;
	int     size;

	i = 0;
	size = 0;
	argv = ft_strsplit(s, ' ');
	if (!argv || !argv[0])
		return ;
	while (argv[size])
		size++;
	i = size - 1;
	while (i >= 0)
	{
		if (!ft_val_dig(argv[i]) || !ft_val_overflow(argv[i]))
		{
			write(2, "Error\n", 6);
			return ;
		}
		top_a = ft_add_elem(&top_a, ft_atoi(argv[i]));
		i--;
	}
	ft_last_val_c(top_a, v);
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

int			checker(int argc, char **argv)
{
	int		i;
	t_stack	*top_a;
	int		v;

	top_a = NULL;
	i = argc - 1;
	v = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
			v = 1;
		if (argc == 2 && v == 0)
			ft_split_val_c(argv[1], top_a, v);
		else if (argc == 3 && v == 1)
			ft_split_val_c(argv[2], top_a, v);
		else
		{
			while (i > 0 + v)
			{
				if (!ft_val_dig(argv[i]) || !ft_val_overflow(argv[i]))
				{
					write(2, "Error\n", 6);
					return (0);
				}
				top_a = ft_add_elem(&top_a, ft_atoi(argv[i]));
				i--;
			}
			ft_last_val_c(top_a, v);
		}
	}
//	unlink("created_instr_i.txt");
//	unlink("created_instr_gt.txt");
	return (2);
}
