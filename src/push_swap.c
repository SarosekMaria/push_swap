/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:18:16 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:06:51 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_last_val(t_stack *top_a)
{
	if (!ft_val_duplicates(&top_a))
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}
	ft_creating_instr(&top_a);
	ft_del_stack(&top_a);
}

void		ft_split_val(char *s, t_stack *top_a)
{
	char	**argv;
	int		i;
	int		size;

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
	ft_last_val(top_a);
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

int			push_swap(int argc, char **argv)
{
	int		i;
	t_stack	*top_a;

	top_a = NULL;
	i = argc - 1;
	unlink("created_instr_i.txt");
	unlink("created_instr_gt.txt");
	if (argc > 1)
	{
		if (argc == 2)
			ft_split_val(argv[1], top_a);
		else
		{
			while (i > 0)
			{
				if (!ft_val_dig(argv[i]) || !ft_val_overflow(argv[i]))
				{
					write(2, "Error\n", 6);
					return (0);
				}
				top_a = ft_add_elem(&top_a, ft_atoi(argv[i]));
				i--;
			}
			ft_last_val(top_a);
		}
	}
	return (0);
}
