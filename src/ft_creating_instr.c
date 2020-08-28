/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creating_instr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:26:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 16:13:10 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pswap.h"

static int		ft_countsize(int fd)
{
	char			*line;
	int				size;

	size = 0;
	if (fd == -1)
		ft_printf("problems with open 'created_instr.txt'\n");
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		size++;
		if (line != NULL)
			ft_strdel(&line);
	}
	if (close(fd) == -1)
		ft_printf("problems with closing 'created_instr.txt'\n");
	return (size);
}

void			ft_print_instr(void)
{
	int			size_i;
	int			size_gt;
	int			fd;
	char		*line;

	size_i = 0;
	size_gt = 0;
	fd = open("created_instr_i.txt", O_RDONLY);
	size_i = ft_countsize(fd);
	fd = open("created_instr_gt.txt", O_RDONLY);
	size_gt = ft_countsize(fd);
	if (size_i <= size_gt)
		fd = open("created_instr_i.txt", O_RDONLY);
	else
		fd = open("created_instr_gt.txt", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("%s\n", line);
		if (line != NULL)
			ft_strdel(&line);
	}
	if (close(fd) == -1)
		ft_printf("problems with closing 'created_instr.txt'\n");
}

void			ft_fdopen(char *name, t_help *h)
{
	h->markup_head = NULL;
	h->fd = open(name, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (h->fd == -1)
		ft_printf("problems with open 'created_instr.txt'\n");
	h->count = 0;
}

void			ft_creating_instr(t_stack **top_a)
{
	t_help		*h;
	t_stack		*top_b;
	t_stack		*head;

	head = NULL;
	top_b = NULL;
	h = (t_help*)malloc(sizeof(t_help) * 1);
	if (!h)
		return ;
	ft_fdopen("created_instr_i.txt", h);
	ft_indexing(top_a);
	head = ft_cpy_stack(&head, top_a);
	ft_markuping(top_a, &ft_index_markup, h);
	ft_sort(top_a, &top_b, &ft_index_markup, h);
	if (close(h->fd) == -1)
		ft_printf("problems with closing 'created_instr.txt'\n");
	ft_fdopen("created_instr_gt.txt", h);
	ft_markuping(&head, &ft_gt_markup, h);
	ft_sort(&head, &top_b, &ft_gt_markup, h);
	if (close(h->fd) == -1)
		ft_printf("problems with closing 'created_instr.txt'\n");
	ft_print_instr();
	ft_del_stack(&head);
	free(h);
}
