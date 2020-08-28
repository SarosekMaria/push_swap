/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:12:29 by sassassi          #+#    #+#             */
/*   Updated: 2020/07/28 16:23:32 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_check_space_empty(char *s)
{
	int		i;
	size_t	spaces;

	i = 0;
	spaces = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			spaces++;
		i++;
	}
	i = 0;
	while (s[i])
		i++;
	if ((i == 1 && s[0] == ' ') || spaces == ft_strlen(s))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (i == 0)
		return (1);
	return (0);
}
