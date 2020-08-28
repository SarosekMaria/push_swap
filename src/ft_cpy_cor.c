/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 15:06:10 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 15:19:37 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void	ft_cpy_cor(t_correct **cor_min, t_correct *current_min)
{
	(*cor_min)->ra = current_min->ra;
	(*cor_min)->rb = current_min->rb;
	(*cor_min)->rr = current_min->rr;
	(*cor_min)->rra = current_min->rra;
	(*cor_min)->rrb = current_min->rrb;
	(*cor_min)->rrr = current_min->rrr;
	(*cor_min)->sa = current_min->sa;
	(*cor_min)->sb = current_min->sb;
	(*cor_min)->ss = current_min->ss;
	(*cor_min)->sum = current_min->sum;
	(*cor_min)->next = NULL;
}
