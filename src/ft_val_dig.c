/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:46:06 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/12 13:40:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static int	ft_char(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
		c == '\r' || c == ' ')
		return (1);
	return (0);
}

int			ft_val_dig(char *s)
{
	int	i;
	int	i_d;
	int	i_first_dig;

	i_first_dig = -1;
	i = 0;
	i_d = 0;
	while (ft_char(s[i]) == 1)
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			if (i_first_dig < 0)
				i_first_dig = i;
			i_d++;
		}
		else if (!((s[i] == '+' || s[i] == '-') &&
			(i_first_dig > i || i_first_dig == -1)) || (i_d > 10))
			return (0);
		i++;
	}
	if (i_d == 0)
		return (0);
	return (1);
}
