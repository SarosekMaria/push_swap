/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_instr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:49:06 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:37:32 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

int			ft_val_instr(char *line)
{
//	char	*line;

//	line = NULL;
//	while (get_next_line(0, &line) > 0)
//	{
		if (ft_strlen(line) == 0)
			return (1);//maybe return (0)
		if (ft_strcmp(line, "sa") != 0 && ft_strcmp(line, "sb") != 0
				&& ft_strcmp(line, "ss") != 0 && ft_strcmp(line, "pa") != 0
				&& ft_strcmp(line, "pb") != 0 && ft_strcmp(line, "ra") != 0
				&& ft_strcmp(line, "rb") != 0 && ft_strcmp(line, "rr") != 0
				&& ft_strcmp(line, "rra") != 0 && ft_strcmp(line, "rrb") != 0
				&& ft_strcmp(line, "rrr") != 0)
		{
			if (line != NULL)
				ft_strdel(&line);
			return (0);
		}
//	}
	return (1);
}
