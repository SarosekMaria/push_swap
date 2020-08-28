# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sassassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 14:24:17 by sassassi          #+#    #+#              #
#    Updated: 2020/07/28 20:49:19 by sassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME_CHECKER = checker
NAME_PUSHSWAP = push_swap
SRC_NAME = ft_check_space_empty.c\
		   ft_free_argv.c\
		   ft_visualize.c\
		   ft_stack_a_end.c\
		   ft_min_stack_elem.c\
		   ft_gt.c\
		   ft_cpy_cor.c\
		   ft_init_correct.c\
		   ft_move_suite_elem.c\
		   ft_order_num.c\
		   ft_find_suite_elem.c\
		   ft_find_suite_pair.c\
		   ft_solve_b.c\
		   ft_three_elem_sort_a.c\
		   ft_index_markup.c\
		   ft_gt_markup.c\
		   ft_indexing.c\
		   ft_cpy_stack.c\
		   ft_markuping.c\
		   ft_val_overflow.c\
		   ft_add_elem.c\
		   ft_val_dig.c\
		   ft_val_instr.c\
		   ft_print_stack.c\
		   ft_del_stack.c\
		   ft_del_elem_st.c\
		   ft_val_duplicates.c\
		   ft_execute.c\
		   ft_pa.c\
		   ft_pb.c\
		   ft_ra_rb.c\
		   ft_rr.c\
		   ft_rra_rrb.c\
		   ft_rrr.c\
		   ft_sa_sb.c\
		   ft_ss.c\
		   ft_stack_size.c\
		   ft_is_sort.c\
		   ft_creating_instr.c\
		   ft_init_mas.c\
		   ft_sort.c\
		   ft_get_bottom.c\
		   ft_is_sort_pswap_asc.c\
		   ft_is_sort_pswap_dsc.c\
		   ft_get_minval_index.c\
		   get_next_line.c
OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
INC_DIR = inludes/
INC = -I $(INC_DIR)
LIB_DIR = src/ft_printf
SRC_DIR = src/

all: $(NAME_PUSHSWAP)

$(NAME_PUSHSWAP): $(OBJ)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) -o $(NAME_PUSHSWAP) $(OBJ) obj/push_swap.o obj/main_pswap.o -L./src/ft_printf -lftprintf -g
	@$(CC) $(CFLAGS) -o $(NAME_CHECKER) $(OBJ) obj/checker.o obj/main_checker.o -L./src/ft_printf -lftprintf -g

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)
	@$(CC) $(CFLAGS) -o obj/push_swap.o -c src/push_swap.c $(INC)
	@$(CC) $(CFLAGS) -o obj/main_pswap.o -c src/main_pswap.c $(INC)
	@$(CC) $(CFLAGS) -o obj/checker.o -c src/checker.c $(INC)
	@$(CC) $(CFLAGS) -o obj/main_checker.o -c src/main_checker.c $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME_CHECKER)
	@/bin/rm -f $(NAME_PUSHSWAP)
	@make -C $(LIB_DIR) fclean

re: fclean all
