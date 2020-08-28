/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_overflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:46:40 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 15:42:31 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int		ft_val_overflow(char *s)
{
	int	size;
	int	nb;

	if (ft_strlen(s) > 10)
		return (0);
	nb = ft_atoi(s);
	size = ft_strlen(s);
	if (nb == -1 && size != 2)
		return (0);
	return (1);
}
