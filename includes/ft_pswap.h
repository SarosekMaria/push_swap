/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:26:53 by sassassi          #+#    #+#             */
/*   Updated: 2020/03/17 12:30:20 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PSWAP_H
# define FT_PSWAP_H

#include <stdio.h>
# define BUFF_SIZE 1
# define MAS_SIZE 12000
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../src/ft_printf/libft/includes/libft.h"

typedef struct			s_stack
{
	int					value;
	int					i;
	int					m;//markup
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct			s_correct
{
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					sa;
	int					sb;
	int					ss;
	int					sum;
	struct s_correct	*next;
}						t_correct;

typedef	struct			s_help
{
	int					fd;
	int					count;
	t_stack				*markup_head;
}						t_help;

t_stack				*ft_add_elem(t_stack **top, int value);
t_stack				*ft_get_bottom(t_stack **top);
t_stack				*ft_cpy_stack(t_stack **dst, t_stack **src);
t_correct			*ft_init_correct(void);
t_correct			*ft_calc_op(t_stack **top_a, t_stack **top_b,
		t_stack *elem_b, t_correct **top_correct);
size_t				ft_stack_size(t_stack **top);
void				ft_move_suite_elem(t_stack **top_a, t_stack **top_b,
		t_correct *cor, int fd);
void				ft_cpy_cor(t_correct **cor_min,
		t_correct *current_min);
void				ft_reinit_correct(t_correct **top_cor);
void				ft_indexing(t_stack **top);
void				ft_sa_sb(t_stack **top);
void				ft_ss(t_stack **top_a, t_stack **top_b);
void				ft_pa(t_stack **top_a, t_stack **top_b);
void				ft_pb(t_stack **top_a, t_stack **top_b);
void				ft_ra_rb(t_stack **top);
void				ft_rr(t_stack **top_a, t_stack **top_b);
void				ft_rra_rrb(t_stack **top);
void				ft_rrr(t_stack **top_a, t_stack **top_b);
void				ft_print_stack(t_stack **top);
void				ft_del_elem_st(t_stack **elem);
void				ft_del_stack(t_stack **top);
void				ft_is_sort(t_stack **top_a, t_stack **top_b);
void				ft_creating_instr(t_stack **top_a);
void				ft_sort(t_stack **top_a, t_stack **top_b,
		int (*mark_f)(t_stack**, t_stack*), t_help *help);
void				ft_markuping(t_stack **top,
		int (*mark_f)(t_stack**, t_stack*), t_help *help);
void				ft_three_elem_sort_a(t_stack **top_a, t_stack **top_b, int fd, int mid);
void				ft_find_suite_elem(t_stack **top_a, t_stack **top_b,
		t_correct **top_correct, t_correct **cor_min);
void				ft_bu_au(int suite_a, int suite_b,
		t_correct *current_cor);
void				ft_bu_ad(int suite_a, int suite_b,
		t_correct *current_cor);
void				ft_bd_au(int suite_a, int suite_b,
		t_correct *current_cor);
void				ft_bd_ad(int suite_a, int suite_b,
		t_correct *current_cor);
void				ft_solve_b(t_stack **top_a,
		t_stack **top_b, int fd);
int					ft_gt(t_stack **top_a, t_stack *elem);
int					ft_order_num(t_stack **top, t_stack *elem);
int					ft_find_suite_pair(t_stack **top_a, t_stack *elem_b);
int					*ft_init_mas(t_stack **top_a, int argc);
int					ft_is_sort_pswap_asc(t_stack **top, size_t size);
int					ft_is_sort_pswap_asc(t_stack **top, size_t size);
int					ft_is_sort_pswap_asc(t_stack **top, size_t size);
int					ft_val_dig(char *s);
int					ft_val_instr(void);
int					ft_printf(const char *format, ...);
int					get_next_line(const int fd, char **line);
int					ft_val_duplicates(t_stack **top);
int					ft_execute(t_stack **top_a);
int					push_swap(int argc, char **argv);
int					checker(int argc, char **argv);
int					ft_is_sort_pswap_asc(t_stack **top, size_t size);
int					ft_is_sort_pswap_dsc(t_stack **top, size_t size);
int					ft_get_minval_index(t_stack **top, int value, int size);
int					ft_val_overflow(char *s);
int					ft_index_markup(t_stack **top, t_stack *markup_head);
int					ft_gt_markup(t_stack **top, t_stack *markup_head);

#endif
