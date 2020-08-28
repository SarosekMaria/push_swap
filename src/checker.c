/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:52:28 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 16:30:39 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_last_val_c(t_stack *top_a, int v)
{
	if (!ft_val_duplicates(&top_a))
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}
	if (ft_execute(&top_a, v) == -1)
	{
		write(2, "Error\n", 6);
		ft_del_stack(&top_a);
		return ;
	}
}

static void	ft_argvlen(char **argv, int *size, int *i)
{
	while (argv[*size])
		(*size)++;
	*i = *size - 1;
}

void		ft_split_val_c(char *s, t_stack *top_a, int v)
{
	char	**argv;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (ft_check_space_empty(s) == 1)
		return ;
	argv = ft_strsplit(s, ' ');
	if (!argv || !argv[0])
		return ;
	ft_argvlen(argv, &size, &i);
	while (i >= 0)
	{
		if (!ft_val_dig(argv[i]) || !ft_val_overflow(argv[i]))
		{
			write(2, "Error\n", 6);
			ft_free_argv(argv);
			return ;
		}
		top_a = ft_add_elem(&top_a, ft_atoi(argv[i]));
		i--;
	}
	ft_last_val_c(top_a, v);
	ft_free_argv(argv);
}

static int	ft_icheck(int v, int i, char **argv, t_stack *top_a)
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
	return (1);
}

int			checker(int argc, char **argv)
{
	t_stack	*top_a;
	int		v;

	top_a = NULL;
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
			if (ft_icheck(v, argc - 1, argv, top_a) == 0)
				return (0);
		}
	}
	return (2);
}
