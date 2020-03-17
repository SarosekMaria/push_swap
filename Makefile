# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:24:17 by sassassi          #+#    #+#              #
#    Updated: 2020/03/17 15:54:36 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
SRC = src/ft_stack_a_end.c src/ft_min_stack_elem.c src/ft_gt.c src/ft_cpy_cor.c src/ft_init_correct.c src/ft_move_suite_elem.c src/ft_order_num.c src/ft_find_suite_elem.c src/ft_find_suite_pair.c src/ft_solve_b.c src/ft_three_elem_sort_a.c src/ft_index_markup.c src/ft_gt_markup.c src/ft_indexing.c src/ft_cpy_stack.c src/ft_markuping.c src/ft_val_overflow.c src/ft_add_elem.c src/ft_val_dig.c src/ft_val_instr.c src/ft_print_stack.c src/get_next_line.c src/ft_del_stack.c src/ft_del_elem_st.c src/ft_val_duplicates.c src/ft_execute.c src/ft_pa.c src/ft_pb.c src/ft_ra_rb.c src/ft_rr.c src/ft_rra_rrb.c src/ft_rrr.c src/ft_sa_sb.c src/ft_ss.c src/ft_stack_size.c src/ft_is_sort.c src/ft_creating_instr.c src/ft_init_mas.c src/ft_sort.c src/ft_get_bottom.c src/ft_is_sort_pswap_asc.c src/ft_is_sort_pswap_dsc.c src/ft_get_minval_index.c
OBJ = ft_stack_a_end.o ft_min_stack_elem.o ft_gt.o ft_cpy_cor.o ft_init_correct.o ft_move_suite_elem.o ft_order_num.o ft_find_suite_elem.o ft_find_suite_pair.o ft_solve_b.o ft_three_elem_sort_a.o ft_index_markup.o ft_gt_markup.o ft_indexing.o ft_cpy_stack.o ft_markuping.o ft_val_overflow.o ft_add_elem.o ft_val_dig.o ft_val_instr.o ft_print_stack.o get_next_line.o ft_del_stack.o ft_del_elem_st.o ft_val_duplicates.o ft_execute.o ft_pa.o ft_pb.o ft_ra_rb.o ft_rr.o ft_rra_rrb.o ft_rrr.o ft_sa_sb.o ft_ss.o ft_stack_size.o ft_is_sort.o ft_creating_instr.o ft_init_mas.o ft_sort.o ft_get_bottom.o ft_is_sort_pswap_asc.o ft_is_sort_pswap_dsc.o ft_get_minval_index.o

INC = includes

all: PROG_BUILD

PROG_BUILD:
	@rm -rf obj
	@rm -rf src/ft_printf/obj
	@mkdir obj
	@mkdir src/ft_printf/obj
	@make -C src/ft_printf/
	@gcc -Wall -Wextra -Werror -c $(SRC) src/push_swap.c src/main_pswap.c -I $(INC) -g
	@gcc -Wall -Wextra -Werror -o $(NAME_PUSHSWAP) $(OBJ) push_swap.o main_pswap.o -L./src/ft_printf -lftprintf -g
	@gcc -Wall -Wextra -Werror -c $(SRC) src/checker.c src/main_checker.c -I $(INC) -g
	@gcc -Wall -Wextra -Werror -o $(NAME_CHECKER) $(OBJ) checker.o main_checker.o -L./src/ft_printf -lftprintf -g
	@mv *.o ./obj/

clean:
	@/bin/rm -f ./obj/*.o
	@/bin/rm -f ./src/ft_printf/obj/*.o

fclean: clean
	@/bin/rm -f $(NAME_CHECKER)
	@/bin/rm -f $(NAME_PUSHSWAP)
	@make -C src/ft_printf/ fclean
	@rm -rf obj
	@rm -rf src/ft_printf/obj

re: fclean all
