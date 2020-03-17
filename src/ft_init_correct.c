/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_correct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 14:53:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 19:26:25 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void			ft_reinit_correct(t_correct **top_cor)
{
	t_correct	*cor;

	cor = *top_cor;
	while (cor)
	{
		cor->ra = 0;
		cor->rb = 0;
		cor->rr = 0;
		cor->rra = 0;
		cor->rrb = 0;
		cor->rrr = 0;
		cor->sa = 0;
		cor->sb = 0;
		cor->ss = 0;
		cor->sum = 0;
		cor = cor->next;
	}
}

t_correct		*ft_init_correct(void)
{
	t_correct   *cor;

	cor = (t_correct*)malloc(sizeof(t_correct) * 1);
	if (!cor)
		return (NULL);
	cor->ra = 0;
	cor->rb = 0;
	cor->rr = 0;
	cor->rra = 0;
	cor->rrb = 0;
	cor->rrr = 0;
	cor->sa = 0;
	cor->sb = 0;
	cor->ss = 0;
	cor->sum = 0;
	cor->next = NULL;
	return (cor);
}
