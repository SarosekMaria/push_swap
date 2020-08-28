/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 18:42:23 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 16:10:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void		ft_insert_sort(int *m, int i)
{
	int		tmp;

	tmp = 0;
	i--;
	while (i >= 0)
	{
		if (m[i] > m[i + 1])
		{
			tmp = m[i + 1];
			m[i + 1] = m[i];
			m[i] = tmp;
		}
		i--;
	}
}

int			*ft_init_mas(t_stack **top_a, int argc)
{
	int		i;
	int		*m;
	t_stack	*tmp;

	i = 0;
	m = NULL;
	if (top_a != NULL)
	{
		tmp = *top_a;
		m = (int*)malloc(sizeof(int) * argc);
		if (!m)
			return (NULL);
		while (tmp && i < argc)
		{
			m[i] = tmp->value;
			ft_insert_sort(m, i);
			tmp = tmp->next;
			i++;
		}
	}
	return (m);
}
