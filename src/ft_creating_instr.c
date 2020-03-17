/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creating_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:26:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/16 13:38:14 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

void			ft_creating_instr(t_stack **top_a)
{
	t_help		*help;
	t_stack 	*top_b;
	t_stack		*head;
	char		*line;

	line = NULL;
	head = NULL;
	top_b = NULL;
	help = (t_help*)malloc(sizeof(t_help) * 1);
	if (!help)
		return ;
	help->markup_head = NULL;
	help->fd = open("created_instr_i.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (help->fd == -1)
		ft_printf("there are problems with open 'created_instr.txt'\n");
	ft_indexing(top_a);
	head = ft_cpy_stack(&head, top_a);
	help->count = 0;
	ft_markuping(top_a, &ft_index_markup, help);
	ft_sort(top_a, &top_b, &ft_index_markup, help);
	if (close(help->fd) == -1)
		ft_printf("there are problems with closing 'created_instr.txt'\n");
	help->fd = open("created_instr_gt.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	help->markup_head = NULL;
	if (help->fd == -1)
		ft_printf("there are problems with open 'created_instr.txt'\n");
	help->count = 0;
	ft_markuping(&head, &ft_gt_markup, help);
	ft_sort(&head, &top_b, &ft_gt_markup, help);
	if (close(help->fd) == -1)
		ft_printf("there are problems with closing 'created_instr.txt'\n");
/*	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (line != NULL)
			ft_strdel(&line);
	}*/
	ft_del_stack(&head);
	unlink("created_instr_i.txt");
	unlink("created_instr_gt.txt");
}
